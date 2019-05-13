#include <iostream>
#include <string>
#include <math.h>
#include "Complex.h"

using namespace std;

float arifm(complexnumber *cn1) {
     return pow(cn1->re*cn1->re+cn1->im*cn1->im,0.5);
     }
void arifm(char tk, complexnumber *cn1, complexnumber *cn2) {
     switch (tk)
     {
     case '+' :
                {
                cout<<cn1->re+cn2->re<<"+"<<cn1->im+cn1->im<<"i";
                break;
                }
     case '-' : {
                cout<<cn1->re-cn2->re<<"+"<<cn1->im-cn2->im<<"i";
                break;
                 }
     case '*' : {
                cout<<cn1->re*cn2->re-cn1->im*cn2->im<<"+"<<cn1->re*cn2->im+cn2->re*cn1->im<<"i";
                break;
                }
     case '/' :{
                if ((cn2->im==0) && (cn2->re==0)) {
                    cout<<"Devision by zero";}
                 else{
                 cout<<(cn1->re*cn2->re+cn1->im*cn2->im)/(cn2->im*cn2->im+cn2->re*cn2->re)<<"+"<<(cn2->re*cn1->im-cn1->re*cn2->im)/(cn2->im*cn2->im+cn2->re*cn2->re)<<"i";}
                break;}
     default:
             {
              cout<<"syntax error ";
                break;
             }
      }
      }
