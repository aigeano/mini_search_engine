#include<stdio.h>
#include<map>
#include<string>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
#include<set>
#include"rapidxml-1.13/rapidxml.hpp"
#include"boost/tokenizer.hpp"
#include"stemmer.h"
#include<stdio.h>
#include"stop.cpp"
using namespace std;
using namespace rapidxml;
using namespace boost;


        map<string, map<string, int> > mp;
        map<string, int>total_words;
        map<string, int>::iterator iti;
	map<string, map<string,int> >::iterator its;
void  index(void)
{

	cout<<"Parsing the xml"<<endl;
	rapidxml::xml_document<>doc;
	rapidxml::xml_node<> * root_node;
        ofstream out("inverted_index.txt");
	ifstream theFile("sample.xml");
	vector<char>buffer((istreambuf_iterator<char>(theFile)),istreambuf_iterator<char>());
	buffer.push_back('\0');
	doc.parse<parse_full>(&buffer[0]);
	root_node = doc.first_node("file");
	vector<string>stopped;


	string txt,docid,title;
	int count;int total;

	for(rapidxml::xml_node<> * page_node = root_node->first_node("page");page_node; page_node = page_node->next_sibling())
	{


		title = page_node->first_node("title")->value();
		docid = page_node->first_node("id")->value();
		txt = page_node->first_node("revision")->first_node("text")->value();
		txt = title+" " + txt;
		tokenizer<>tok(txt);
	      	total = 0;

		for(tokenizer<>::iterator beg = tok.begin(); beg!= tok.end(); ++beg)
		{ 

			it = stop.find(*beg);

			if(it == stop.end())
			{
				stopped.push_back(*beg);
				total++;
			}

		}


		char ss[100];

		memset(&ss[0], 0, sizeof(ss));

		int i , j;
		for( i = 0;i<stopped.size();i++)
		{

			for(j = 0;j<stopped[i].size();j++ )
			{
				ss[j] = stopped[i][j];

			}
			s = (char *) malloc(i_max+1);
			if(stemfile(ss)!= NULL)
				stopped[i] = stemfile(ss);
			free(s);

			memset(&ss[0], 0, sizeof(ss));


		}

		for(int k = 0; k<stopped.size();k++) {
			//      out<<st[k]<<endl;

			mp[stopped[k]][docid]++;
		}
               total_words[docid] = total;



	}

/*	for (its=mp.begin();its!=mp.end();its++) {
		cout << (*its).first<< "   {";
		for(iti=its->second.begin();iti!=its->second.end();iti++)
			cout<<iti->first<<" -> "<<iti->second<<"; ";
	         cout<<"  }"<<endl;
	} */

}
