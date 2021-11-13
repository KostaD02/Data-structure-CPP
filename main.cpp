#include <iostream> //standartuli input/output stremebis biblioteka
#include <string> //stringebis biblioteka 
#include <cstdlib> //damatebiti funqciebis shemotana

using namespace std; //standartul saxelta sivrce

class Node { // Avgwerot node klasi
	public: //gia velis cvladebi
		string data; //avgwerot data cvladi
		Node* next; //avgwerot next mnishvneloba node tipad
};

class Stack { // Gamovacxadot klasis staki sakutrebirvad 
	private: //daxuruli velis cvladebi
		Node* head; //gamovacxadot node klasis tipis satavo elementi
		int length; //gamovacxadot sigrdze
	public: //gia velis cvladebi
		Stack(){ //konstruqtori
			head = NULL; //tavidan head mnishvnelobas mivaniwot null 
			length = 0; //tavidan sigrdzes mivaniwot 0
		}
	//gamovacxadot prototipi funqciebi romlebsac shemdgomshi avgwert
	void push(std::string); //avgwerot damatebis funqcia
	string pop(); //avgwerot amogebis funqcia
	string peek(); // gamovitanot satavo elementi 
	void printStack(); //avgwerot stekis gamotanis funqcia
	bool isEmpty(); //avgwerot funqcia romelic dagvibrunebs mnishvnelobas aris tu ara steki carieli
};

void Stack::push(string data) { //vacxadebt funqcias romelitac stekshi axal elements davamatebt
	Node* newnode = new Node(); //gamovyot axali mexsierebis ubani
	newnode->data = data; //mivaniwot mas mnishvneloba 
	newnode->next = head; //mivaniwot mas satavo elementi
	head = newnode; //satavo elements mivaniwot axali sheqmnili node elementi
	length++; //sigrdze gavzardot ertit
}

string Stack::pop() { //vacxadebt funqcias romelitac stekidan vagdebt satavo mnishvnelobas
	if (isEmpty()){ //shevamowmot aris tu ara steki carieli
		cout<<" Steki carielia elementebs ver gamovitant"<<endl; //vamcnobot momxarebels rom steki carielia da elementi ar aris masshi
		return "\0"; //vabrunebt stringis mnishvnelobas
	}
	//radganac carieli ar aris gavaketot shemdgomi moqmedebebi
	std::string returnData = ""; //vqmnit dasabrunebel mnishvnelobas radganac stekidan amogebuli elementis dakargva ar gvinda
	returnData = head->data; //vaniwebt amosageb mnishvnelobas
	Node* deleteNode = head; //vacxadebt nodis tipis elements da vaniwebt mas satavo elemnts
	head = head->next; //satavo elements vxdit shemdgom elements
	delete deleteNode; //vshlit elements radgan ar gvinda mexsiereba daitvirtos
	length--; //radganac elementi amoviget misi sigrdzec unda shemcirdes 
	return returnData; //vabrunebt amogebul elements
}


string Stack::peek() { //vacxadebt funqcias romelitac vbewdavt satavo elements
	if (isEmpty()){ //vamowmebt aris tu ara steki carieli
		cout<<" Steki carielia elementebs ver gamovitant"<<endl; //vamcnobot momxarebels rom steki carielia da elementi ar aris masshi
		return "\0"; //vabrunebt stringis mnishvnelobas
	}
	return head->data; //vabrunebt satavo elements
}

void Stack::printStack() { //vacxadebt funqcias romelitac shesadzlebeli iqneba stekebis elementebis gamotana
	if (head == NULL){ //vamowmebt satavo elementi udris tu ara null
		cout<<" Steki carielia elementebs ver gamovitant"<<endl; //radganac satavo elementi null aris , sheudzelbelia shemdgomi elementis dabewvda
	}
	Node* iNode = head; //vacxadebt node tipis axal cvlads da vaniwebt mas satavo elements
	cout<<" "; // carieli sapce
	for(int i=0; i<length; i++){ //daviwyot cikli 0 dan stekis elementebis dasasrulamde
		cout<<iNode->data<<" "; //gamogvaqvs mnishnveloba
		iNode = iNode->next; //vaniwebt shemdgom elements
	}
	cout<<endl; //vizualze xazis dasasruli
}

bool Stack::isEmpty() { //vacxadebt funqcias romelitac davadgent aris tu ara steki carieliv
	if (head == NULL) return true; //vamowmebt aris tu ara steki carieli , tu carielia vabrunebt trues
	else return false; //vabrunebt false
}

void menu(){ //vacxadebt menu funcqias
	Stack myStack; //vacxadebt steks
	string data = ""; //vacxadebt data mnishnvelobas
	string returnData = ""; //vacxadebt dasabrunebel mnishvnelobas
	char userChoise = 'k'; //vacxadebt momxareblis archevans
	while(true){ //usasrulo cikli
		system("CLS"); //vizualis gasuftaveba
		cout<<"===============================\n"; //vizualizacia
		cout<<"= Stekebi da mati gamoyeneba  =\n"; //vizualizacia
		cout<<"===============================\n"; //vizualizacia
		cout<<"= Airchiet sasruveli varianti =\n"; //vizualizacia
		cout<<"===============================\n"; //vizualizacia
		cout<<"= 1)Elementis damateba        =\n"; //vizualizacia
		cout<<"= 2)Elementis amogdeba        =\n"; //vizualizacia
		cout<<"= 3)Satavo elementis gamotana =\n"; //vizualizacia
		cout<<"= 4)Carielia steki ?          =\n"; //vizualizacia 
		cout<<"= 5)Stekis gamotana           =\n"; //vizualizacia
		cout<<"= 6)Kodis avtori              =\n"; //vizualizacia
		cout<<"= 7)Programis gatishva        =\n"; //vizualizacia
		cout<<"===============================\n"; //vizualizacia
		cout<<" Tqveni archevani : ";cin>>userChoise; //momxmarebels vtxovt rom sheiyvanos archevani
		if(userChoise == '1'){ 
			//elementis damateba
			cout<<" Sheiyvanet elementi : ";cin>>data; //momxarebels sheyavs monacemi
			myStack.push(data); //monacemi shegvyavs stekshi
		}else if(userChoise == '2'){
			//elementis amogdeba
			returnData = myStack.pop(); //dasabrunebel cvlads vaniwebt stekidan amovardnil mnishnvelobas
			if(!returnData.empty()){ //vamomwebt stekis sicarielese
				cout<<" Amovarda : "<<returnData<<endl; //vachvnebt momxarebls amovardnil elements
			}
			system("PAUSE"); //dapauzeba rom sheamchnios momxmarebelma ra amovarda
		}else if(userChoise == '3'){ 
			//satavo elementis gamoatna
			returnData = myStack.peek(); //dasabrunebel mnishnvelobas vaniwebt satavo elementis mnishnvelobas
			if(!returnData.empty()){ //vamowmebt stekis sicarielese
				cout<<" Satavo elementi : "<<returnData<<endl; //gamogvaqvs momxareblistvis satavo elementi
			}
			system("PAUSE"); //dapauzeba rom sheamchnios momxmarebelma ra amovarda
		}else if(userChoise == '4'){
			//carielia tu ara steki
			if(myStack.isEmpty()){ //vamowmebt stekis sicarielese
				cout<<" Steki carielia "<<endl; //vachvenebt momxarebels ro steki aris carieli
			}else{ //danarcheni situacia
				cout<<" Steki ar aris carieli "<<endl; //vachvenebt momxarebels ro steki ar aris carieli
			}
			system("PAUSE"); //vacherebt programas rom moxmarebelma dainaxos mititeba
		}else if(userChoise == '5'){
			//mteli stekis gamotana
			cout<<" Stekis elementebi : \n"; //vizualizacia
			myStack.printStack(); //gamovaqvs mteli steki
			system("PAUSE"); //vacherebt programas rom moxmarebelma dainaxos mititeba
		}else if(userChoise == '6'){
			//kodis avtoris chveneba
			cout<<" Code by Konstantine Datunishvili"<<endl; //vizualizacia
			cout<<" Github : https://github.com/kostad02"<<endl; //vizualizacia
			cout<<" Github repository : https://github.com/KostaD02/Stack-in-C"<<endl; //vizualizacia
			system("PAUSE");//vacherebt programas rom moxmarebelma dainaxos mititeba
		}else if(userChoise == '7'){
			exit(0); //gamovdivart menu funqciidan
		}else{
			menu(); //araswori input vidzaxebt tavidan
		}
	}
}

int main(int argc, char** argv) { //main funqcia
	menu(); //vidzaxebt menu funqcias
	return 0; //warmatebit dasruleba
}
