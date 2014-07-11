
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
using namespace std;

set<string>stop;
set<string>::iterator it;

void stopwords()
{


		fstream file("stopWords");
			while(!file.eof())
					{
			string line;
              		getline(file,line);    							stop.insert(line);

													}


}












