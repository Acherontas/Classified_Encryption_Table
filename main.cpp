/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/*
 * File:   main.cpp
 * Author: Aionnio
 *
 * Created on 5 Αυγούστου 2023, 3:59 μ.μ.
 */

  //  std::setlocale(LC_ALL, "en_US.UTF-8");
   // std::locale::global(std::locale("en_US.UTF-8"));
   // std::wcout.imbue(std::locale());
   // std::wstring s = L"λογος";
   // std::wcout << s.at(0) << std::endl;
//#include <locale>
//#include <io.h>
//#include <fcntl.h>
//#include<cwchar>

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <atomic>
#include <thread>
#include <climits>
#include <limits>
#include <iomanip>
#include <vector>
#include <sstream>
#include <list>
#include <cstring>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

/*
 *
 */

string result;
int i;
int lines=0;
int letspl;
string cmd;//="C:\\a.txt";
const int kl=12;
const int tbl_thr[kl]={-1,2,1,9,8,7,6,5,4,3,3};
const int tbl_six[kl]={-1,5,4,3,2,1,9,8,7,6,6};
const int tbl_nine[kl]={-1,8,7,6,5,4,3,2,1,9,0};
string wordd;
string nm;
//char lstblo[]="011";char lstbltw[]="021";char lstblthr[]="031";
//int base=3;
string fnls;
string ppooss="";
const char x=100;
const char y=100;
char oflstvl[x];
string ofvlnv[y];
int xx=0;
int yy=0;
const string ml="01";
string lm="01";
int mlinc=1;
char ch_seper;
int showtbl=0;
int openit(){
   string data;
   ifstream infile;
   infile.open(cmd);
   string mnm;
   while(!infile.eof()){
       letspl=0;
    //   cout<<"\n";
  //  cout << "Reading from the file" << endl;
    infile>> data;
    for(i=0;i<=data.size()-1;i++)
    {
        if(i==0 && data.at(0)==','){data.at(0)=' ';}
        if(data.at(i)!=','){
            mnm+=data.at(i);
         //   cout<<"i is " << i << " " << data.at(i)<<"  ";
            letspl+=1;}
    }
   // cout<<"\n";
    letspl-=1;
    data.clear();
    lines+=1;
   // cout<<"letters " << letspl << " lines " << lines << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
   // cout<<"line " << lines << " with letters as  " << letspl << " and line as " << mnm <<"\n";
    result+=mnm;
    mnm.clear();
  //  cout<<"\n";
   }
    return 0;
}
int posset(int ptbl,int vlpos,char vl){
    ppooss+=" ";
    ppooss+=vl;
    ppooss+=":";
    ppooss+=to_string(ptbl);
    ppooss+=to_string(vlpos);
    ppooss+=" ";
    return 0;
}
int retrv_lst(int i,int ck,int kk,int lst){
//    if(i>1 && ck==1 && lst==0){// cout<<"\n";cout<<"rr " << result.at(kk-3)  <<"\n";
//    oflstvl[xx]=result.at(kk-3);ofvlnv[yy]=lm; xx+=1;yy+=1;  mlinc+=1; lm.clear(); lm=ml; lm+=to_string(mlinc);
//    }
//    if(i>1 && lst==1){// cout<<"\n";cout<<"rrr " << result.at(kk-1)  <<"\n";
//    oflstvl[xx]=result.at(kk-1);ofvlnv[yy]=lm; xx+=1;yy+=1; mlinc+=1; lm.clear(); lm=ml; lm+=to_string(mlinc);
//    }
    oflstvl[xx]=result.at(kk-1);ofvlnv[yy]=lm; xx+=1;yy+=1;  mlinc+=1; lm.clear(); lm=ml; lm+=to_string(mlinc);
    return 0;
}
string spe;
int unfold(int o,char vl,int onthefly){
    int k=0;
    int c=0;
    int r;
    if(o==0 ){
    k=0;
    for(int i=1;i<=lines;i++)
    {
        if(result.at(k)==' ')
        {
            if(showtbl==1){
            cout<<"\n";
            cout<<"Table " << i << " values of :\n"; }
            c=0;
            k+=1;
            //cout<<"values of  : " <<"\n";
            while(result.at(k)!=' ')
            {
               c+=1;
               if(showtbl==1){
               cout<<c  << "  " <<  result.at(k) <<   " | " ;   //
             }
               k+=1;
               if(k==result.size()){
                   //cout<<"k " << k << " " << i << " " << c << " " << result.at(k-1) << "\n";
                   break;}
            }
        }
             r=retrv_lst(i,c,k,1);
             std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    }
    if(o==1 )
    {
     k=0;
     c=0;
     int setp;
    for(int i=1;i<=lines;i++)
    {
        if(result.at(k)==' ')
        {
            c=0;
          //  cout<<"Table " << i << "\n";
            k+=1;
          //  cout<<"values of  : " <<"\n";
            while(result.at(k)!=' ')
            {
                c+=1;
                if(vl==result.at(k) ){
                   // cout<<"vl " << vl << " with " << result.at(k) <<"\n";

                    if(onthefly==1){
                    if(c<=9){ nm+=to_string(c);
                    setp=posset(i,c,result.at(k));
                    }
                    if(c>9){nm+=to_string(0);
                    setp=posset(i,c,result.at(k));
                    }
                    }
                    if(onthefly==0){
                      //  cout<<"onthefly vl " << vl << " with " << result.at(k) <<"\n";
                        spe+=to_string(c);
                    }
                }
            //   cout<<c <<  "  " <<  result.at(k) <<   " | " ;
               k+=1;
               if(k==result.size()){break;}
            }
        }
    }
    }
    return 0;
}
string spl;


int cdi=0;
int fl=0;
int mnu=0;
 int cd( long long int n){
     //cout<<"inserting for adding digits " << mk <<"\n";
    mnu=n%10;
   // cdi+=m;
    fl=-1;
    if(n/10==0){
        fl=1;
               if(fl==1){ }
               return mnu;   //return 1;
    }
    else
    {
        cd(n/10);  //return 1 + cd(n/10);
    }
    return mnu;
}

int polk;
int gener(string nm,int otf,int bse){
    cout<<"generating with " << nm << " and " << otf <<  " and base of " << bse << "\n";
    char k;
    int mk=0;
    int lk=0;
 //generating the numbers;
   int gav=0;
   for(int i=0;i<=nm.size()-1;i++)
    {  gav=0;
        k=nm.at(i);
        //cout<<"k is " << k <<"\n";
        if(!isspace(k)){
            //cout<<"its not a space\n";
            gav=stoi(&k);
        //cout<<"new value of k is gav " << gav <<"\n";
        }
      //  if(k!=' ' || !isspace(k)){gav=stoi(&k);
        //cout<<"gav is " << gav <<"\n";
        //}
       // if(k==ch_seper){fnls+=" ";goto B;}
        //if(k==' ' || isspace(k)){fnls+=" ";goto B;}
        if(isspace(k)){fnls+=" ";goto B;}
        mk=0;
        lk=0;
      //  cout<<"gav is " << gav <<"\n";
        //cout<<"before the for\n";

        polk=cd(gav);
        gav=polk;
        //cout<<"kl " << polk <<"\n";
        for(;;){
          //  cout<<"inside the for\n";

            // cout<<"trying with  gav and mk " << gav << " " << mk << " and k " << k << "\n";

        if(gav==mk){
            //cout<<"entering gav and mk " << gav << " " << mk  << "  and k " << k <<"\n";
            if(mk>0 && mk<=9){
                if(otf==1){
                if(bse==3){fnls+=to_string(tbl_thr[mk]);}
                if(bse==6){fnls+=to_string(tbl_six[mk]);}
                if(bse==9){fnls+=to_string(tbl_nine[mk]);}
                }
              //  cout<<"fnls " << fnls <<"\n";
                if(otf==0){
                if(bse==3){spl+=to_string(tbl_thr[mk]);}
                if(bse==6){spl+=to_string(tbl_six[mk]);}
                if(bse==9){spl+=to_string(tbl_nine[mk]);}
               }
             //   cout<<"spl " << spl <<"\n";
            }
            if(mk==0 || mk >9){
                if(bse==3){
                if(otf==1){fnls+=to_string(3);}
                if(otf==0){spl+=to_string(3);}
                }
                if(bse==6){
                if(otf==1){fnls+=to_string(6);}
                if(otf==0){spl+=to_string(6);}
                }
                 if(bse==9){
                if(otf==1){fnls+=to_string(0);}
                if(otf==0){spl+=to_string(0);}
                }
            //    cout<<"fnls " << fnls <<"\n";
            //    cout<<"spl " << spl <<"\n";
                }
             lk=1;break;
            }
         mk+=1;
         if(lk==1){//cout<<"found and moving\n";
         break;}
        }
          B:cout<<"";
        }
   return 0;
}
string lexeis[100000];
int get_lexeis(string word,char seper){
    int cnt=1;
    string lexi;
    for(int i=0;i<=word.size()-1;i++)
    {
        if(word.at(i)!=seper){lexi+=word.at(i);}
        if(word.at(i)==seper){//cout<<cnt << " word is " << lexi <<"\n";
            lexeis[cnt]=lexi;
            cnt+=1;
            lexi.clear();
        }
    }
    return cnt-1;
}
int add_spe(string word,char seper){
    int m=word.size();
    char k=word.at(m-1);
    int rt;
    if(k==seper){rt=0;}
    if(k!=seper){rt=1;}
    return rt;
}
string m;
int ent=0;
int tblbase[10000];
int tblbs=1;
int allow_change_to_base;
int main(int argc, char** argv) {
    cout<<"voyeristic behaviours and others have fun xD\n";
    cout<<"exoume kai leme xD  : 1:diadromi arxeiou pinakon 2:analisi pinakon [0-1] 3:allagi vasis gia kathe lexi[0-1] \n";
    cout<<"\n";
    cmd=argv[1];
    showtbl=stoi(argv[2]);
    allow_change_to_base=stoi(argv[3]);
    //setlocale(LC_ALL,"greek");
    //setlocale(LC_ALL,"en_US.UTF-8");
    cout<<"give a seperator\n";
    cin>>ch_seper;
    cout<<"\n";
    cout<<"your seperator " << ch_seper <<"\n";
    cout<<"\n";
    cout<<"give a word\n";
    cin>>wordd;
    cout<<"\n";
    cout<<"you give " << wordd <<"\n";
    cout<<"\n";
    int l=add_spe(wordd,ch_seper);
    if(l==1){wordd+=ch_seper;cout<<"new word is " << wordd <<"\n";}
    cout<<"\n";
    int lx=get_lexeis(wordd,ch_seper);
    cout<<"Arithmos lexeon " << lx << "\n";
    if(allow_change_to_base==1){
        int bsa;
    cout<<"------------------------\n";
    for(int i=1;i<=lx;i++)
    {cout<<"\n";
        cout<<i << " with " << lexeis[i] <<"\n";
    cout<<"Enter base 3 6 or 9 \n"; cin >> bsa; tblbase[tblbs]=bsa;
    cout<<lexeis[i] << " with base " << tblbase[tblbs] <<"\n";
    tblbs+=1;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));}
    cout<<"------------------------\n";}
    cout <<"\n";
    int m=openit();
    cout<<"result " << result <<"\n";
    cout<<"\n";
    cout<<"the lines creates " << lines << " tables in memory " <<"\n";
    int kl=unfold(0,' ',0);
    cout<<"moving out of the unfold with value : " << kl <<"\n";
    cout<<"\n";
    if(allow_change_to_base==0){
    for(int i=0;i<=wordd.size()-1;i++)
    {
        if(wordd.at(i)==ch_seper ){nm+=" ";
        if(ent==0){
        int ml=unfold(1,wordd.at(i),0);
        cout<<"\n";
        cout<<"starting generating with spe: " << spe <<"\n";
        int mkm=gener(spe,0,3);
        cout<<"\n";
        ent+=1;}
        }
        if(wordd.at(i)!=ch_seper){int ml=unfold(1,wordd.at(i),1);}
    }
    }
    if(allow_change_to_base==1){
        string lxicur;
        string bsk;
        string nmi;
        string fnlss;
        string pos;
        int k;
        int ml=unfold(1,ch_seper,0);
        cout<<"\n";int mkm=gener(spe,0,3);
        cout<<"\n";
        for(int i=1;i<=lx;i++){
            lxicur.clear();
            nm.clear();
            fnls.clear();
            ppooss.clear();
            lxicur+=lexeis[i];
            k=i;
           // cout<<"lxicur " << lexeis[i] << " " << tblbase[k] <<"\n";
            for(int m=0;m<=lxicur.size()-1;m++){
                int ml=unfold(1,lxicur.at(m),1);
            }
             cout<<"moving with lexi " << lxicur <<"\n";
             int gn=gener(nm,1,tblbase[k]);
             cout<<"\n";
             nmi+=nm;
             nmi+=" ";
             fnlss+=fnls;
             fnlss+=" ";
             bsk+=to_string(tblbase[k]);
             bsk+=" ";
             pos+=ppooss;
             pos+=" ";
            // std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
            cout <<"\n";
            cout<<"word is : " << wordd<<"\n";
            cout<<"\n";
            cout<<"Semi-Code :  " << nmi <<"\n";
            cout<<"\n";
            cout<<"with base : " << bsk <<"\n";
            cout<<"\n";
            cout<<"Final Encoding : " << fnlss <<"\n";
            cout<<"\n";
            cout<<"--------------------------\n";
            cout<<"With Encoding : " << pos<<"\n";
    }
    if(allow_change_to_base==0){
        cout <<"\n";
            cout<<"word is " << wordd<<"\n";
            cout<<"\n";
    cout<<"\n";
    cout<<"Semi-Code :  " << nm <<"\n";
    cout<<"\n";
    int bcho;
    cout<<"choose a generic base\n";
    cin>>bcho;
    cout<<"you choose base : " << bcho << "\n";
    //if(bcho!=3 || bcho!=6 || bcho!=9){cout<<" Wrong Base. Exiting\n"; goto E;}
    cout<<"\n";
    int gen=gener(nm,1,bcho);
    cout<<"\n";
    cout<<"with base : " << bcho <<"\n";
    cout<<"\n";
    cout<<"Final Encoding : " << fnls <<"\n";
    cout<<"\n";
    cout<<"--------------------------\n";
    cout<<"With Encoding " << ppooss<<"\n";
    cout<<"\n";
    }
    cout<<"and seperator " << ch_seper <<  " with Number "  << spe << " And Generating Number  " << spl  << "\n";
    for(int i=0;i<=xx-1;i++)
    {
        cout<<"with value of : " << oflstvl[i] << " as " << ofvlnv[i] <<"\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    cout<<"--------------------------\n";

   // E:cout<<" ";

    return 0;
}

