#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_set> //taking unrepeated numbers
#include <fstream>

using namespace std;
//class of all question types
class question {
protected: //becaise we will inherit from this class
	string type;
	string theqestion;
	string ans_tf;
	string ans_complete;
	string ans_mcq[4];
public:
	question()
	{
		theqestion = "";
		ans_tf = "";
		ans_complete = "";
		ans_mcq[0] = "";
		ans_mcq[1] = "";
		ans_mcq[2] = "";
		ans_mcq[3] = "";
	}
	//function to set the main question
	void setquestion(string question)
	{
		theqestion = question;
	}
	//function to set the answer of complete question
	void set_completeans(string answer)
	{
		ans_complete = answer;
	}
	//function to set the 4 answers of MCQ question
	void set_mcqans(string arr[4])
	{
		for (int i = 0; i < 4; i++)
		{
			ans_mcq[i] = arr[i];
		}
	}
	//function to set the answer of TF question
	void set_tfans(string answer)
	{
		ans_tf = answer;
	}
	//funtion to set the type of the question
	void set_type(string type)
	{
		this->type = type;
	}
	//function to get the main question
	string getquestion()
	{
		return theqestion;
	}
	//function to get the answer of Tf question
	string get_tfans()
	{
		return ans_tf;
	}
	//function to get the answer of complete question
	string get_completeans()
	{
		return ans_complete;
	}
	//function to get the answer of MCQ questions
	string* get_mcqans()
	{
		return ans_mcq;
	}
	//function to get the right answer of MCQ questions
	string get_1stmcq()
	{
		return ans_mcq[0];
	}
	//function to get the type of the question
	string get_type()
	{
		return type;
	}
};
//class of questions of type (True and False)
class tf_q :public question {
public:
	void setquestion(string question)
	{
		theqestion = question;
	}
	void set_tfans(string answer)
	{
		ans_tf = answer;
	}
};
//class of questions of type (Complete questions)
class complete_q :public question {
public:
	void setquestion(string question)
	{
		theqestion = question;
	}
	void set_completeans(string answer)
	{
		ans_complete = answer;
	}
};
//class of questions of type (MCQ)
class mcq_q :public question {
public:
	void setquestion(string question)
	{
		theqestion = question;
	}
	void set_mcqans(string arr[4])
	{
		for (int i = 0; i < 4; i++)
		{
			ans_mcq[i] = arr[i];
		}
	}
};
//admin's class
class admin {
protected://data types are protected because we will inherit from this class
	string firstname;
	string lastname;
	string role;
	string username;
	string password;
public:
	//constructor to set default values
	admin()
	{
		firstname = "User";
		lastname = "User";
		role = "Admin";
		username = "Admin";
		password = "Admin";
	}
	string getfirstname()
	{
		return firstname;
	}
	string getlastname()
	{
		return lastname;
	}
	string getusername()
	{
		return username;
	}
	string getrole()
	{
		return role;
	}
	string getpassword()
	{
		return password;
	}
	void updatename(string name)
	{
		firstname = name;
	}
	void adminwelcomemessage()
	{
		cout << "Welcome user " << firstname << " (ADMIN), please choose from the following options:" << endl <<
			"\t[1] Switch accounts" << endl <<
			"\t[2] Update your name" << endl <<
			"\t[3] View all users" << endl <<
			"\t[4] Add new user" << endl <<
			"\t[5] View all questions" << endl <<
			"\t[6] Add new question" << endl <<
			"\t[7] Load questions from file" << endl <<
			"\t[8] Exit the program" << endl;

	}
	void setusername(string username)
	{
		this->username = username;
	}
	void setfirstname(string firstname)
	{
		this->firstname = firstname;
	}
	void setlastname(string lastname)
	{
		this->lastname = lastname;
	}
	void setrole(string role)
	{
		this->role = role;
	}
	void setpassword(string password)
	{
		this->password = password;
	}
};
//player's class
class player :public admin {
private:
	int numofquizes, numofmcq, numofcomplete, numoftf;
	int mcqscore, tfscore, completescore;
	int mcqmaxscore, tfmaxscore, completemaxscore;
	vector<int>scores;
	vector<int>maxscores;
	vector<int>numofrightanswers;//the number of right answer of each quiz
public:
	player()
	{
		numofquizes = 0;
		numofcomplete = 0;
		numofmcq = 0;
		numoftf = 0;
		mcqscore = 0;
		tfscore = 0;
		mcqmaxscore = 0;
		tfmaxscore = 0;
		completemaxscore = 0;
		completescore = 0;
		firstname = "User";
		lastname = "User";
		username = "Player";
		role = "Player";
		password = "Player";
	}
	void set_numofquizes(int numofquizes)
	{
		this->numofquizes = numofquizes;
	}
	void set_scores(int num)
	{
		scores.push_back(num);
	}
	void set_maxscores(int num)
	{
		maxscores.push_back(num);
	}
	void set_mcqnum(int n)//mcq....set_mcqnum(1);
	{
		numofmcq += n;
	}
	void set_tfnum(int n)
	{
		numoftf += n;
	}
	void set_completenum(int n)
	{
		numofcomplete += n;
	}
	int get_numofmcq()
	{
		return numofmcq;
	}
	int get_numoftf()
	{
		return numoftf;
	}
	int get_numofcomplete()
	{
		return numofcomplete;
	}
	//get the highest score 
	float get_highestscore()
	{
		int score = scores.at(0);
		int temp = 0;
		for (int i = 0; i < scores.size(); i++)
		{
			if (scores.at(i) > score)
			{
				score = scores.at(i);
				temp = i;
			}
		}
		return(float((float)score / (float)maxscores.at(temp)) * 10.0);
	}
	//get the lowest score
	float get_lowestscore()
	{
		int score = scores.at(0);
		int temp = 0;
		for (int i = 0; i < scores.size(); i++)
		{
			if (scores.at(i) < score)
			{
				score = scores.at(i);
				temp = i;
			}
		}
		return(float((float)score / (float)maxscores.at(temp)) * 10.0);
	}
	int get_numofquizes()
	{
		return numofquizes;
	}
	string getfirstname()
	{
		return firstname;
	}
	string getlastname()
	{
		return lastname;
	}
	string getrole()
	{
		return role;
	}
	string getusername()
	{
		return username;
	}
	string getpassword()
	{
		return password;
	}
	void playerwelcomemessage()
	{
		cout << "Welcome user " << firstname << " (Player), please choose from the following options:" << endl <<
			"[1] Switch accounts  " << endl <<
			"[2] Update your name " << endl <<
			"[3] Start a new quiz " << endl <<
			"[4] Display your scores statistics " << endl <<
			"[5] Display all your scores" << endl <<
			"[6] Exit the program " << endl;


	}
	//function to set the score of mcq questions 
	void set_mcqscore(int num)//right mcq ... set_mcqscore(2)
	{
		mcqscore += num;
	}
	//function to set the score of mcq questions 
	void set_mcqmaxscore(int num)
	{
		mcqmaxscore += num;
	}
	//function to set the score of tf questions 
	void set_tfscore(int num)
	{
		tfscore += num;
	}
	//function to set the score of tf questions 
	void set_tfmaxscore(int num)
	{
		tfmaxscore += num;
	}
	//function to set the score of complete questions 
	void set_completescore(int num)
	{
		completescore += num;
	}
	//function to set the score of complete questions 
	void set_completemaxscore(int num)
	{
		completemaxscore += num;
	}
	//function to get the max score of mcq questions
	int get_mcqmaxscore()
	{
		return mcqmaxscore;
	}
	//function to get the score of mcq questions
	int get_mcqscore()
	{
		return mcqscore;
	}
	//function to get the max score of tf questions
	int get_tfmaxscore()
	{
		return tfmaxscore;
	}
	//function to get the score of tf questions
	int get_tfscore()
	{
		return tfscore;
	}
	//function to get the max score of complete questions
	int get_completemaxscore()
	{
		return completemaxscore;
	}
	//function to get the score of complete questions
	int get_completescore()
	{
		return completescore;
	}
	//function to put the number of the right answers of each quiz in the vector
	void set_rightanswer(int n)
	{
		numofrightanswers.push_back(n);
	}
	//function to get the number of the right answers
	int get_rightanswer(int i)
	{
		return(numofrightanswers.at(i));
	}
};
//function to print all questions
void print_all(vector<question>Qv, vector<tf_q>Tv, vector<complete_q>Cv, vector<mcq_q>Mv)
{
	string temparr[4] = { "","","","" };
	int counter = 1;
	cout << "Number of questions available : " << Qv.size() << endl;
	cout << "----------------------------------------" << endl;
	cout << "MCQ Questions list (Total: " << Mv.size() << " Questions)" << endl;
	for (int i = 0; i < Qv.size(); i++)
	{
		if (Qv.at(i).get_1stmcq() != "")
		{

			vector<int>tempvec; //vector to put the random choices in it
			cout << "[" << counter << "]" << "(ID: " << i + 1 << ")" << Qv.at(i).getquestion() << endl;
			unordered_set<int>numset;
			while (numset.size() != 4)
			{
				numset.insert(rand() % 4);
			}
			for (auto i = numset.begin(); i != numset.end(); i++)
			{
				tempvec.push_back(*i);
			}
			//loop to put "*" before the right answer
			for (int j = 0; j < 4; j++)
			{
				if (Qv.at(i).get_mcqans()[tempvec.at(j)] == Qv.at(i).get_1stmcq())
				{
					Qv.at(i).get_mcqans()[tempvec.at(j)] = "*" + Qv.at(i).get_mcqans()[tempvec.at(j)];
				}
			}
			cout << "\t [a] " << Qv.at(i).get_mcqans()[tempvec.at(0)] << "\t[c] " << Qv.at(i).get_mcqans()[tempvec.at(1)] << "\t[d] " << Qv.at(i).get_mcqans()[tempvec.at(2)] << "\t[e] " << Qv.at(i).get_mcqans()[tempvec.at(3)] << endl;
			counter++;
		}
	}
	cout << "----------------------------------------" << endl;
	cout << "TF Questions list (Total: " << Tv.size() << " questions)" << endl;
	for (int i = 0; i < Qv.size(); i++)
	{
		if (Qv.at(i).get_tfans() != "")
		{
			cout << "[" << counter << "]" << "(ID: " << i + 1 << ")" << Qv.at(i).getquestion() << "(Answer:" << Qv.at(i).get_tfans() << ")" << endl;
			counter++;
		}
	}
	cout << "----------------------------------------" << endl;
	cout << "COMPLETE Questions list (Total: " << Cv.size() << " questions)" << endl;
	for (int i = 0; i < Qv.size(); i++)
	{
		if (Qv.at(i).get_completeans() != "")
		{
			cout << "[" << counter << "]" << "(ID: " << i + 1 << ")" << Qv.at(i).getquestion() << "(Answer:" << Qv.at(i).get_completeans() << ")" << endl;
			counter++;
		}
	}
	cout << "----------------------------------------" << endl << endl << endl;


}

int main()
{
	srand(time(0));
	vector<admin>adminsvec;
	vector<player>playersvec;
	vector<question>questionsvec;
	vector<tf_q>tfvec;
	vector<complete_q>completevec;
	vector<mcq_q>mcqvec;
	admin defaultadmin;
	player defaultplayer;
	adminsvec.push_back(defaultadmin);
	playersvec.push_back(defaultplayer);
	string username, password;
	bool checklogin = false;
	cout << "*******************************************************************" << endl <<
		"Welcome to the Quiz game program V2.0!" << endl <<
		"*******************************************************************" << endl;
beginlogin:
	cout << "Please enter your username: " << endl;
	cin >> username;
	cout << "Please enter your password: " << endl;
	cin >> password;
	for (int i = 0; i < adminsvec.size(); i++)
	{
		if (username == adminsvec.at(i).getusername())
		{
			if (password == adminsvec.at(i).getpassword())
			{
				int adminchoice;
			adminstart:
				adminsvec.at(i).adminwelcomemessage();
				checklogin = true;
				cin >> adminchoice;
				if (adminchoice == 1)
				{
					goto beginlogin;
				}
				else if (adminchoice == 2)
				{
					system("cls");
					cout << "Enter your name" << endl;
					string name;
					cin >> name;
					adminsvec.at(i).updatename(name);
					system("cls");
					goto adminstart;

				}
				else if (adminchoice == 3)//view all users
				{
					system("cls");
					cout << "First name \t" << right << " Last name \t" << right << " Username \t" << right << " Role " << endl;
					for (int i = 0; i < adminsvec.size(); i++)
					{
						cout << adminsvec.at(i).getfirstname() << "\t\t " << right << adminsvec.at(i).getlastname() << "\t\t " << right << adminsvec.at(i).getusername() << "\t\t " << right << adminsvec.at(i).getrole() << endl;
					}
					for (int i = 0; i < playersvec.size(); i++)
					{
						cout << playersvec.at(i).getfirstname() << "\t\t " << right << playersvec.at(i).getlastname() << "\t\t " << right << playersvec.at(i).getusername() << "\t\t " << right << playersvec.at(i).getrole() << endl;
					}
					cout << endl << endl;
					goto adminstart;
				}
				else if (adminchoice == 4)//add new user
				{
					bool checkfornew = false;
					string newusername, newfirstname, newlastname, newpassword, newrole;
					cout << "Enter the username : ";
				addnew:
					cin >> newusername;
					for (int i = 0; i < adminsvec.size(); i++)
					{
						if (newusername == adminsvec.at(i).getusername())
						{
							checkfornew = true;
						}
					}
					for (int i = 0; i < playersvec.size(); i++)
					{
						if (newusername == playersvec.at(i).getusername())
						{
							checkfornew = true;
						}
					}
					if (checkfornew == true)
					{
						cout << "This Username is already exist , re-enter another one" << endl;
						goto addnew;
					}
					else
					{
						cout << "Enter the first name : ";
						cin >> newfirstname;
						cout << "Enter the last name : ";
						cin >> newlastname;
						cout << "Enter the role : ";
						cin >> newrole;
						cout << "Enter the password : ";
						cin >> newpassword;
						if (newrole == "Admin" || newrole == "admin" || newrole == "ADMIN")
						{
							admin A;
							A.setfirstname(newfirstname);
							A.setlastname(newlastname);
							A.setpassword(newpassword);
							A.setrole(newrole);
							A.setusername(newusername);
							adminsvec.push_back(A);
							system("cls");
							goto adminstart;
						}
						else if (newrole == "Player" || newrole == "player" || newrole == "PLAYER")
						{
							player P;
							P.setfirstname(newfirstname);
							P.setlastname(newlastname);
							P.setpassword(newpassword);
							P.setrole(newrole);
							P.setusername(newusername);
							playersvec.push_back(P);
							system("cls");
							goto adminstart;
						}
					}
				}
				else if (adminchoice == 5)//view all questions
				{
					char charchoice;
					int numchoice;
					print_all(questionsvec, tfvec, completevec, mcqvec);
					cout << "Press [d] and the question ID if you want to delete a question (Example: d 2) " << endl;
					cout << "Press [b] if you want to go back to the main menu" << endl;
					cin >> charchoice;
					if (charchoice == 'b')
					{
						goto adminstart;
					}
					else if (charchoice == 'd')
					{
						cin >> numchoice;
						for (int i = 0; i < tfvec.size(); i++)
						{
							if (questionsvec.at(numchoice - 1).getquestion() == tfvec.at(i).getquestion())
							{
								tfvec.erase(tfvec.begin() + i);
							}
						}
						for (int i = 0; i < completevec.size(); i++)
						{
							if (questionsvec.at(numchoice - 1).getquestion() == completevec.at(i).getquestion())
							{
								completevec.erase(completevec.begin() + i);
							}
						}
						for (int i = 0; i < mcqvec.size(); i++)
						{
							if (questionsvec.at(numchoice - 1).getquestion() == mcqvec.at(i).getquestion())
							{
								mcqvec.erase(mcqvec.begin() + i);
							}
						}
						questionsvec.erase(questionsvec.begin() + numchoice - 1);
						system("cls");
						cout << "Question deleted" << endl;

					}

					goto adminstart;

				}
				else if (adminchoice == 6)//add new question
				{
					string thequestion, answer, answerarr[4];
					string questiontype;
					do
					{
						cout << "Which type of question do you want to add ?.." << endl;
						cout << "\t 1-MCQ" << endl;
						cout << "\t 2-Complete" << endl;
						cout << "\t 3-TF" << endl;
						cin >> questiontype;
						if (questiontype == "1")
						{
							question Q;
							mcq_q M;
							cout << "Enter the question : " << endl;
							cin.ignore();
							getline(cin, thequestion);
							cout << "Enter the first answer : ";
							getline(cin, answerarr[0]);
							cout << "Enter the other three answers : " << endl;
							getline(cin, answerarr[1]);
							getline(cin, answerarr[2]);
							getline(cin, answerarr[3]);
							M.setquestion(thequestion);
							M.set_mcqans(answerarr);
							Q.setquestion(thequestion);
							Q.set_mcqans(answerarr);
							Q.set_type("MCQ");
							mcqvec.push_back(M);
							questionsvec.push_back(Q);
							system("cls");
							cout << "Question added" << endl;
							goto adminstart;

						}
						else if (questiontype == "2")
						{
							question Q;
							complete_q C;
							cout << "Enter the question : " << endl;
							cin.ignore();
							getline(cin, thequestion);
							cout << "Enter the answer : ";
							getline(cin, answer);
							C.setquestion(thequestion);
							C.set_completeans(answer);
							Q.setquestion(thequestion);
							Q.set_completeans(answer);
							Q.set_type("COMPLETE");
							completevec.push_back(C);
							questionsvec.push_back(Q);
							system("cls");
							cout << "Question added" << endl;
							goto adminstart;
						}
						else if (questiontype == "3")
						{
							question Q;
							tf_q T;
							cout << "Enter the question : " << endl;
							cin.ignore();
							getline(cin, thequestion);
							cout << "Enter the answer which ('true' Or 'false') : ";
							getline(cin, answer);
							T.setquestion(thequestion);
							T.set_tfans(answer);
							Q.setquestion(thequestion);
							Q.set_tfans(answer);
							Q.set_type("TF");
							tfvec.push_back(T);
							questionsvec.push_back(Q);
							system("cls");
							cout << "Question added" << endl;
							goto adminstart;

						}
						else
						{
							system("cls");
							cout << "Wrong choice !..." << endl;
						}
					} while (questiontype != "1" && questiontype != "2" && questiontype != "3");
					goto adminstart;
				}
				else if (adminchoice == 7)//load questions from file
				{
					string path, temp;
					vector<string>filevec;
					cout << "Enter the path of the txt file : " << endl;
				pathlogin:
					cin >> path;
					fstream file(path, ios::in);
					if (!file)
					{
						cout << "File not found ... , re-enter the path : " << endl;
						goto pathlogin;
					}
					while (!file.eof())// taking questions from the file 
					{
						getline(file, temp);
						filevec.push_back(temp);
					}
					for (int i = 0; i < filevec.size(); i++)
					{
						if (filevec.at(i) == "MCQ")
						{
							string temparr[4];
							temparr[0] = filevec.at(i + 2);
							temparr[1] = filevec.at(i + 3);
							temparr[2] = filevec.at(i + 4);
							temparr[3] = filevec.at(i + 5);
							question Q;
							mcq_q MQ;
							Q.setquestion(filevec.at(i + 1));
							Q.set_mcqans(temparr);
							Q.set_type("MCQ");
							MQ.setquestion(filevec.at(i + 1));
							MQ.set_mcqans(temparr);
							questionsvec.push_back(Q);
							mcqvec.push_back(MQ);
						}
						else if (filevec.at(i) == "COMPLETE")
						{
							question Q;
							complete_q CQ;
							Q.setquestion(filevec.at(i + 1));
							Q.set_completeans(filevec.at(i + 2));
							Q.set_type("COMPLETE");
							CQ.setquestion(filevec.at(i + 1));
							CQ.set_completeans(filevec.at(i + 2));
							questionsvec.push_back(Q);
							completevec.push_back(CQ);
						}
						else if (filevec.at(i) == "TF")
						{
							question Q;
							tf_q TQ;
							Q.setquestion(filevec.at(i + 1));
							Q.set_tfans(filevec.at(i + 2));
							Q.set_type("TF");
							TQ.setquestion(filevec.at(i + 1));
							TQ.set_tfans(filevec.at(i + 2));
							questionsvec.push_back(Q);
							tfvec.push_back(TQ);
						}
					}
					system("cls");
					cout << "Questions loaded...." << endl;
					goto adminstart;
				}
				else if (adminchoice == 8)
				{
					exit(42);
				}

			}
		}
	}
	for (int i = 0; i < playersvec.size(); i++)
	{
		int temp = i;
		if (username == playersvec.at(i).getusername())
		{
			if (password == playersvec.at(i).getpassword())
			{
				int playerchoice;
			playerstart:
				playersvec.at(i).playerwelcomemessage();
				checklogin = true;
				cin >> playerchoice;
				if (playerchoice == 1)
				{
					goto beginlogin;
				}
				else if (playerchoice == 2)
				{

					system("cls");
					cout << "Enter your name" << endl;
					string name;
					cin >> name;
					playersvec.at(i).updatename(name);
					system("cls");
					goto playerstart;
				}
				else if (playerchoice == 3)//start a new quiz
				{
					int rightanswers = 0;
					int counter = 1;
					if (questionsvec.size() < 5)
					{
						system("cls");
						cout << "Questions isn't enough please add more questions" << endl;
						goto playerstart;
					}
					else
					{

						unordered_set<int> qset;
						vector<int>qnumvec;
						while (qset.size() != 5)
						{
							qset.insert(rand() % questionsvec.size());
						}
						for (auto it = qset.begin(); it != qset.end(); it++)
						{
							qnumvec.push_back(*it);//push set elements
						}
						qset.clear();
						int score = 0, maxscore = 0;
						for (int i = 0; i < 5; i++)
						{
							string answer;
							cout << questionsvec.at(qnumvec.at(i)).getquestion() << endl;
							if (questionsvec.at(qnumvec.at(i)).get_type() == "MCQ")
							{
								playersvec.at(temp).set_mcqmaxscore(2);
								playersvec.at(temp).set_mcqnum(1);
								string answersarr[4];
								vector <int> numvec;
								unordered_set<int>answers_set;
								while (answers_set.size() != 4)
								{
									answers_set.insert(rand() % 4);
								}
								for (auto i = answers_set.begin(); i != answers_set.end(); i++)
								{
									numvec.push_back(*i);//حطينا ارقام السيت
								}
								cout << "[A]  " << questionsvec.at(qnumvec.at(i)).get_mcqans()[numvec.at(0)] << " ";
								cout << "[B]  " << questionsvec.at(qnumvec.at(i)).get_mcqans()[numvec.at(1)] << " ";
								cout << "[C]  " << questionsvec.at(qnumvec.at(i)).get_mcqans()[numvec.at(2)] << " ";
								cout << "[D]  " << questionsvec.at(qnumvec.at(i)).get_mcqans()[numvec.at(3)] << endl;
								cin >> answer;
								if (answer == "A")
								{
									if (questionsvec.at(qnumvec.at(i)).get_mcqans()[numvec.at(0)] == questionsvec.at(qnumvec.at(i)).get_1stmcq())
									{
										cout << "You are right " << endl;
										playersvec.at(temp).set_mcqscore(2);
										score += 2;
										rightanswers++;
									}
									else
									{
										cout << "Wrong answer" << endl;


									}
								}
								else if (answer == "B")
								{
									if (questionsvec.at(qnumvec.at(i)).get_mcqans()[numvec.at(1)] == questionsvec.at(qnumvec.at(i)).get_1stmcq())
									{
										playersvec.at(temp).set_mcqscore(2);
										cout << "You are right " << endl;
										score += 2;
										rightanswers++;
									}
									else
									{
										cout << "Wrong answer" << endl;
									}
								}
								else if (answer == "C")
								{
									if (questionsvec.at(qnumvec.at(i)).get_mcqans()[numvec.at(2)] == questionsvec.at(qnumvec.at(i)).get_1stmcq())
									{
										playersvec.at(temp).set_mcqscore(2);
										cout << "You are right " << endl;
										score += 2;
										rightanswers++;
									}
									else
									{
										cout << "Wrong answer" << endl;
									}

								}
								else if (answer == "D")
								{
									if (questionsvec.at(qnumvec.at(i)).get_mcqans()[numvec.at(3)] == questionsvec.at(qnumvec.at(i)).get_1stmcq())
									{
										playersvec.at(temp).set_mcqscore(2);
										cout << "You are right " << endl;
										score += 2;
										rightanswers++;
									}
									else
									{
										cout << "Wrong answer" << endl;
									}
								}
								maxscore += 2;
							}
							else if ((questionsvec.at(qnumvec.at(i)).get_type() == "COMPLETE"))
							{
								playersvec.at(temp).set_completemaxscore(3);
								playersvec.at(temp).set_completenum(1);
								cin >> answer;
								if (answer == questionsvec.at(qnumvec.at(i)).get_completeans())
								{
									playersvec.at(temp).set_completescore(3);
									cout << "You are right" << endl;
									score += 3;
									rightanswers++;
								}
								else
								{
									cout << "Wrong answer" << endl;
								}
								maxscore += 3;
							}
							else if ((questionsvec.at(qnumvec.at(i)).get_type() == "TF"))
							{
								playersvec.at(temp).set_tfmaxscore(1);
								playersvec.at(temp).set_tfnum(1);
								cin >> answer;
								if (answer == questionsvec.at(qnumvec.at(i)).get_tfans())
								{
									playersvec.at(temp).set_tfscore(1);
									cout << "You are right" << endl;
									score += 1;
									rightanswers++;
								}
								else
								{
									cout << "Wrong answer" << endl;
								}
								maxscore += 1;
							}


						}
						playersvec.at(i).set_numofquizes(counter);
						playersvec.at(i).set_scores(score);
						playersvec.at(i).set_maxscores(maxscore);
						counter++;
						system("cls");
						cout << "Quiz is finished" << endl;
						playersvec.at(i).set_rightanswer(rightanswers);
					}
					goto playerstart;
				}
				else if (playerchoice == 4)
				{
					cout << "Your score statistics per quiz: " << endl;
					cout << "\t -Number of Quizzes taken : " << playersvec.at(i).get_numofquizes() << endl;
					cout << "\t -Highest quiz score : " << playersvec.at(i).get_highestscore() << "/10" << endl;
					cout << "\t -Lowest quiz score : " << playersvec.at(i).get_lowestscore() << "/10" << endl;
					cout << "Your score statistics per question type: " << endl;
					cout << "\t- Number of MCQ questions:" << playersvec.at(i).get_numofmcq() << endl;
					cout << "\t- Number of TF questions:" << playersvec.at(i).get_numoftf() << endl;
					cout << "\t- Number of COMPLETE questions:" << playersvec.at(i).get_numofcomplete() << endl;
					cout << "\t- Average grade for MCQ questions: " << float(float(playersvec.at(i).get_mcqscore()) / float(playersvec.at(i).get_mcqmaxscore())) * 2.0 << "/2" << endl;
					cout << "\t- Average grade for COMPLETE questions: " << float(float(playersvec.at(i).get_completescore()) / float(playersvec.at(i).get_completemaxscore())) * 3.0 << "/3" << endl;
					cout << "\t- Average grade for TF questions: " << float(float(playersvec.at(i).get_tfscore()) / float(playersvec.at(i).get_tfmaxscore())) << "/1" << endl;
					cout << "Press [b] of you want to go back to the main menu or [e] to exit " << endl;
					string choice;
					cin >> choice;
					if (choice == "b")
						goto playerstart;
					else
						exit(42);


				}
				else if (playerchoice == 5)
				{
					cout << "The number of quizes you finished : " << playersvec.at(i).get_numofquizes() << endl;
					for (int x = 0; x < playersvec.at(i).get_numofquizes(); x++)
					{
						cout << "Quiz number : " << x + 1 << endl;
						cout << "\t The number of right answers : " << playersvec.at(i).get_rightanswer(x) << endl;
						cout << "\t The number of wrong answers : " << 5 - playersvec.at(i).get_rightanswer(x) << endl;
						cout << "Press [b] of you want to go back to the main menu or [e] to exit " << endl;
						string choice;
						cin >> choice;
						if (choice == "b")
							goto playerstart;
						else
							exit(42);
					}
				}

				else if (playerchoice == 6)
				{
					exit(42);
				}
			}
		}
	}
	if (checklogin == false)
	{
		system("cls");
		cout << "Wrong username or password or both" << endl;
		goto beginlogin;
	}



	return 0;
}
