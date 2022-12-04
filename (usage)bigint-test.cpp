#include<bits/stdc++.h>
#include "bigint.hpp"
int main(){
	bigint a,b;
	cout<<"Please input a,b:\n";
	a.get();
	b.get();
	cout<<"a.length:   "<<a.length()<<"\na:          ";
	a.put();
	cout<<"\n";
	cout<<"b.length:   "<<b.length()<<"\nb:          ";
	b.put();
	cout<<"\n";
	cout<<"a<b:        "<<(a<b)<<"\n";
	cout<<"a>b:        "<<(a>b)<<"\n";
	cout<<"a==b:       "<<(a==b)<<"\n";
	cout<<"a!=b:       "<<(a!=b)<<"\n";
	bigint c=a+b;
	cout<<"c=a+b\n";
	cout<<"c.length:   "<<c.length()<<"\nc:          ";
	c.put();
	cout<<"\n";
	bigint d=a-b;
	cout<<"d=a-b\n";
	cout<<"d.length:   "<<d.length()<<"\nd:          ";
	d.put();
	cout<<"\n";
	bigint e=-a;
	cout<<"e=-a\n";
	cout<<"e.length:   "<<e.length()<<"\ne:          ";
	e.put();
	cout<<"\n";
	return 0;
}
