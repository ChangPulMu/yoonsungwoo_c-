#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

namespace COMP_POS{
	enum {CLERK=1, SENIOR, ASSIST, MANAGER};
}

class NameCard{
	private:
		char * name;
		char * company;
		char * num;
		int level;
	public:
		NameCard(char * n, char * c, char * nm, int l){
			name = new char[strlen(n)+1];
			company = new char[strlen(c)+1];
			num = new char[strlen(nm)+1];

			strcpy(name, n);
			strcpy(company, c);
			strcpy(num, nm);

			level = l;
		}
		~NameCard(){ //동적 할당을 해줬으면 꼭 소멸자를 만들어 줍시다!
			delete []name;
			delete []company;
			delete []num;
		}
		void ShowNameCardInfo(){
			cout<<"이름: "<<name<<endl;
			cout<<"회사: "<<company<<endl;
			cout<<"전화번호: "<<num<<endl;
			cout<<"직급: ";
			switch(level){
				case 1:
					cout<<"사원"<<endl<<endl;
					break;
				case 2:
					cout<<"주임"<<endl<<endl;
					break;
				case 3:
					cout<<"대리"<<endl<<endl;
					break;
				case 4:
					cout<<"과장"<<endl<<endl;
					break;
			}
		}
};

int main(void){
	NameCard manClerk("Lee","ABCEng","010-1111-2222",COMP_POS::CLERK);
	NameCard manSenior("Hong","OrangeEng","010-3333-4444",COMP_POS::SENIOR);
	NameCard manAssist("Kim","SoGoodComp","010-5555-6666",COMP_POS::ASSIST);

	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

	return 0;
}
