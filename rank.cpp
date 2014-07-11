
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<fstream>
#include"try6.cpp"
using namespace std;
int main()
	{
           index();
	  cout<<"Enter your Query"<<endl;
	  char arr[100];
	 scanf("%s",arr);
	 s= (char *)malloc(i_max+1);
	  string q = stemfile(arr);
	  free(s);
	  its = mp.find(q);
	  if(its==mp.end())
	  {
		cout<<"No results Found"<<endl;
		exit(0);

	}
        double tf=0.0; double idf;
         map<string, double>rank;
         map<string , double>::iterator it;
 for(iti = its->second.begin();iti!= its->second.end();iti++)
	 {
		tf   = (iti->second/(double)total_words[iti->first]);

	   	idf = log(18.0/its->second.size());
//                 cout<<tf<<" ----"<<idf<<endl;

           rank[iti->first] = tf * idf;
	 }
         

         multimap<double, string>res;

         multimap<double, string>::iterator itr;
      for (it = rank.begin();it!=rank.end();it++)
	    //   cout<<it->first<<"->"<<it->second<<endl;
//		 res[it->second] = it->first;
              res.insert(pair<double, string>(it->second,it->first)) ;


      cout<<"The following documents were found : the doc ids are in order of ranking"<<endl;

      
      for (itr = res.begin();itr!=res.end();itr++)
	      cout<<"Doc -id" <<itr->second<<endl;
      
      
      
      
      
      
      /*
     just checking values !!!!!!! 
         
	 iti = its->second.begin();
	 cout<<iti->second<<"----"<<total_words[iti->first]<<endl;
          cout<<its->second.size()<<endl;
	   	idf = log(18.0/its->second.size());
	  cout<<"idf -- "<<idf<<endl;*/
	}
