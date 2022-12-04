#ifndef BIGINT_HPP
#define BIGINT_HPP
#include<bits/stdc++.h>
using namespace std;
class bigint{
	private:
		typedef unsigned long long              len_type   ;
		typedef deque<int>                      arr_type   ;
		typedef deque<int>::iterator            iter       ;
		typedef deque<int>::reverse_iterator    rev_iter   ;
		typedef bool                            neg_type   ;
		len_type len;
		arr_type num;
		neg_type is_neg;
		void delfirst0(){
			while((!num.front())&&len>1){
				num.pop_front();
				--len;
			}
			if(len==1&&(!num.front())) is_neg=0;
			return;
		}
	public:
		bigint(){
			len=1;
			is_neg=0;
			num.clear();
			num.push_back(0);
			return;
		}
		bigint(bigint *&other){
			len=other->len;
			num=other->num;
			is_neg=other->is_neg;
			return;
		}
		bigint& swap(bigint &other){
			std::swap(len,other.len);
			num.swap(other.num);
			std::swap(is_neg,other.is_neg);
			return *this;
		}
		bigint& operator=(bigint other){
			len=other.len;
			num=other.num;
			is_neg=other.is_neg;
			return *this;
		}
		bigint& clear(){
			len=1;
			is_neg=0;
			num.clear();
			num.push_back(0);
			return *this;
		}
		bigint& get(){
			len=0;
			is_neg=0;
			num.clear();
			char q=getchar();
			while(q<48||q>57){
				if(q=='-') is_neg=1;
				else is_neg=0;
				q=getchar();
			}
			while(q>47&&q<58){
				++len;
				num.push_back(q-48);
				q=getchar();
			}
			delfirst0();
			return *this;
		}
		bigint& put(){
			if(is_neg) putchar('-');
			iter e=num.end();
			for(iter f=num.begin();f!=e;++f) putchar((*f)+48);
			return *this;
		}
		inline len_type length(){
			return len;
		}
		bool operator>(bigint other){
			if(is_neg!=other.is_neg) return is_neg<other.is_neg;
			if(len!=other.len) return (len>other.len)^is_neg;
			bool m=0;
			iter ae=num.end(),be=other.num.end();
			for(iter af=num.begin(),bf=other.num.begin();af!=ae;++af,++bf)
				if((*af)!=(*bf)){
					m=(*af)>(*bf);
					break;
				}
			return is_neg^m;
		}
		bool operator<(bigint other){
			if(is_neg!=other.is_neg) return is_neg>other.is_neg;
			if(len!=other.len) return (len<other.len)^is_neg;
			bool m=0;
			iter ae=num.end(),be=other.num.end();
			for(iter af=num.begin(),bf=other.num.begin();af!=ae;++af,++bf)
				if((*af)!=(*bf)){
					m=(*af)<(*bf);
					break;
				}
			return is_neg^m;
		}
		bool operator==(bigint other){
			if(is_neg!=other.is_neg) return 0;
			if(len!=other.len) return 0;
			iter ae=num.end(),be=other.num.end();
			for(iter af=num.begin(),bf=other.num.begin();af!=ae;++af,++bf)
				if((*af)!=(*bf))
					return 0;
			return 1;
		}
		bool operator!=(bigint other){
			if(is_neg!=other.is_neg) return 1;
			if(len!=other.len) return 1;
			iter ae=num.end(),be=other.num.end();
			for(iter af=num.begin(),bf=other.num.begin();af!=ae;++af,++bf)
				if((*af)!=(*bf))
					return 1;
			return 0;
		}
		bigint operator-(){
			bigint s=*this;
			s.is_neg=(!s.is_neg);
			s.delfirst0();
			return s;
		}
		bigint operator+(bigint other){
			bigint a=*this,b=other;
			if(is_neg^other.is_neg){
				if(is_neg){
					a.is_neg=0;
					if(a>b){
						bigint c=a-b;
						c.is_neg=1;
						return c;
					}
					return b-a;
				}
				else{
					b.is_neg=0;
					if(b>a){
						bigint c=b-a;
						c.is_neg=1;
						return c;
					}
					return a-b;
				}
			}
			else if(is_neg){
				a.is_neg=0;
				b.is_neg=0;
				bigint c=a+b;
				c.is_neg=1;
				return c;
			}
			if(len<other.len) a.swap(b);
			rev_iter ae=a.num.rend(),be=b.num.rend(),af=a.num.rbegin(),bf=b.num.rbegin();
			for(;be!=bf;++af,++bf){
				*af+=*bf;
				if(*af>9){
					if(++af==ae){
						++a.len;
						a.num.push_front(*--af/10);
						*af%=10;
						a.delfirst0();
						return a;
					}
					++*af--;
					*af-=10;
				}
			}
			for(;ae!=af;++af){
				if(*af<10) break;
				if(++af==ae){
					++a.len;
					a.num.push_front(1);
					*--af-=10;
					a.delfirst0();
					return a;
				}
				++*af--;
				*af-=10;
			}
			a.delfirst0();
			return a;
		}
		bigint operator-(bigint other){
			bigint a=*this,b=other;
			if(is_neg^other.is_neg){
				if(is_neg){
					a.is_neg=0;
					bigint c=a+b;
					c.is_neg=1;
					return c;
				}
				else{
					b.is_neg=0;
					return a+b;
				}
			}
			else if(is_neg){
				a.is_neg=0;
				b.is_neg=0;
				return b-a;
			}
			if(a<b){
				a.swap(b);
				a.is_neg=1;
			}
			rev_iter ae=a.num.rend(),be=b.num.rend(),af=a.num.rbegin(),bf=b.num.rbegin();
			for(;be!=bf;++af,++bf){
				*af-=*bf;
				if(*af<0){
					--*++af;
					*--af+=10;
				}
			}
			for(;ae!=af;++af){
				if(*af<10) break;
				--*++af--;
				*af+=10;
			}
			a.delfirst0();
			return a;
		}
};
#endif
