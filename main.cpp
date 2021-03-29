//
//  main.cpp
//  Sort_Names
//
//  Created by MAC on 2/12/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;


//El primero es para ordenar palabras usando vector
void print(vector<string> names){
    cout<<"Printing.....";
    cout<<endl;
    for(int i=0;i<names.size();i++)
      cout<<names[i]<<endl;
    cout<<endl;
}

bool mycomp(string a, string b){
    return a<b;
}

vector<string> alphabaticallySort (vector<string> a){
    //int n=a.size();
    sort(a.begin(), a.end(), mycomp);
    return a;
}

int main(int argc, const char * argv[]) {
    
    //Cargar linea por linea en un array de strings
    
    string line;
    string arrayline[4];
    ifstream inpInitialRoute("library_holdings.txt");
    for(int iline=0;iline<4;++iline)
    {
        if(getline(inpInitialRoute,line))
        {
            arrayline[iline]=line;
            cout<<arrayline[iline]<<endl;
        }
    }
    inpInitialRoute.close();
    cout<<"Route 1: "<<arrayline[1]<<endl;
    cout<<"Route 0: "<<arrayline[0]<<endl;
    cout<<"Route 2: "<<arrayline[2]<<endl;
    
    
    // insert code here...Ordena usando vector
    int n;
    cout<<"Enter number of names to be added: ";
    cin>>n;
    cout<<endl;
    
    vector<string> names;
    string name;
    cout<<"Enter names: "<<endl;
    
    for(int i=0;i<n;i++){
        cin>>name;
        names.push_back(name);
    }
    
    cout<<endl<<"Before sorting"<<endl;
    print(names);
    
    names=alphabaticallySort(names);
    
    cout<<"After alphabetical sorting"<<endl;
    print(names);
    
    //El segundo es para comparar strings como nombre de autor o del libro y ordenar
    //Ojo:Esta parte es para seleccionar y ordenar strings-->array bidimentional ij
    cout<<endl;
    std::string string_one = "Carlos Saco";
        std::string string_two = "Abel Cisneros";

        if (string_one < string_two) {
            std::cout << "\"" << string_one << "\" is less than \"" << string_two << "\"" << std::endl;
        }
        else{
            std::cout << "\""<< string_two << "\" is less than \"" << string_one << "\"" << std::endl;
        }
    
    
    //El tercero es para separar del string nombres, generos o titulos
    cout<<endl;
    string s[3];
    s[0]="C0594 Woolf   Virginia    A Room of One   essay   available";
    s[1]="C7495    Gibson    William    Neuromencer    science fiction    available";
    s[2]="C1934    Heidegger    Martin    Being and Time    philosophy    unavailable";

   // char char_array[][];
    int tabcount=0;
    for(int j=0;j<3;j++)
    {
    
        int n;
        n=s[j].length();
        
     char char_array[3][100];
    // char_array[j][n+1];
     strcpy(char_array[j],s[j].c_str());
     for(int a=0;a<n+1;a++)
     {
      if(char_array[j][a]==' ')//OJO esto es porque no leiia tab en MAC OS
      {
       char_array[j][a]='_';
      }
      else if(char_array[j][a]=='A')
      {
          tabcount=tabcount+1;
      }
         
         //cout<<endl;
      cout<<char_array[j][a];
     }cout<<endl;
    }
    cout<<"Tabs hay "<<tabcount;
    cout<<endl;
    
    
    
    
        
    return 0;
}
