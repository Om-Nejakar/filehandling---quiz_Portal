#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    fstream queFile;
    fstream ansFile;
    string line, correctAnswer;
    string ans;
    int score=0, totalque=0;

    queFile.open("questions.txt", ios::in); //open the question file
    if(queFile.is_open())
    {
        ansFile.open("answers.txt", ios::in); //open the answer file
        if(ansFile.is_open())
        {
            while(getline(queFile, line)) // get the question first 
            {
                if(line.empty()) continue;
                cout<< line << endl;

                for(int i=0;i<4;i++) // get the options 
                {
                    getline(queFile, line);
                    cout << line << endl;
                }

                cout<<"choose a-d : "; // choose the answer
                cin>>ans;
                totalque++;

                getline(ansFile, correctAnswer);

                if(ans == correctAnswer) // verify the answer 
                {
                    cout<<"correct! "<<endl;
                    score++;
                }
                else
                {
                    cout<<"wrong answer " << "correct " << correctAnswer<<endl;
                }
            }
            ansFile.close();
        }
        queFile.close();
        cout<<"total score "<<score<<" out of "<<totalque<<endl; // print the answers
    }

}