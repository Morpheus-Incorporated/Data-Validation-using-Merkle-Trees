#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

#include "../BinaryTree/BinaryTree.hpp"
#include "../MerkleTree/MerkleTree.hpp"

using namespace std;

char** stringProcess(string inputString,int);
int packetSize;

// Menu Driven Program.
int main()
{
    cout<<"                                            Data Validation Program                "<<endl;
    cout<<" 1 - Send a message"<<endl<<" 2 - Check for Validation"<<endl;

    int input;
    unsigned long int masterHash;
    char charInput,tamperFlag;

    string message,tamperedMessage;
    fstream masterHashFile,msgPacketsFile;

    cin>>input;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int splitSize;
    unsigned long long int *hashArray;

    cout<<"Enter split size :";
    cin>>splitSize;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(splitSize == 2)
        splitSize = 2;
    else if(splitSize % 4 != 0)
        splitSize -= splitSize%4;
    if(input == 1)
    {
        Merkle_Tree T(1);

        cout<<"Enter your message :";

        getline(cin,message,'\n');

        char** msgPackets = stringProcess(message,splitSize);
        hashArray = T.createMerkleTree(msgPackets,splitSize);
        cout<<endl;
        
        T.levelOrderTraversal( T.getRoot() );
        masterHash = T.getMasterRoot();

        cout<<endl<<"The Master Hash is: "<<masterHash<<endl;
        cout<<"Do you want to tamper the msg (Y/n) :"<<endl;

        cin>>tamperFlag;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if(tamperFlag == 'n')
        {
            masterHashFile.open("masterHash.txt");
            masterHashFile << masterHash;
            masterHashFile.close();
            msgPacketsFile.open("msgPackets.txt");
            for(int i = 0; i < splitSize; i++)
            {
                string inputPart(msgPackets[i],packetSize);
                msgPacketsFile << inputPart <<endl;
            }
            msgPacketsFile.close();
        }
        else if(tamperFlag == 'Y' || tamperFlag == 'y')
        {
            cout<<"Enter your Tampered message :";
            getline(cin,tamperedMessage,'\n');
            char** msgPacketsTampered = stringProcess(tamperedMessage,splitSize);
            msgPacketsFile.open("msgPackets.txt");
            for(int i = 0; i < splitSize; i++)
            {
                string inputPart(msgPacketsTampered[i],packetSize);
                msgPacketsFile << inputPart <<endl;
            }
            msgPacketsFile.close();
        }
    }
    cout<<"Do you want to check for Validation (Y/n): ";
    cin>>charInput;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    ifstream receiverPacketsFile;
    if(charInput == 'Y' || charInput == 'y')
    {
        string inputFromFile;
        char** receiverMessage = new char* [splitSize];
        receiverPacketsFile.open("msgPackets.txt");
        for(int i = 0; i < splitSize; i++)
        {
            receiverPacketsFile >> inputFromFile;
            cout << inputFromFile << endl;
            char *cstr = new char[inputFromFile.length() + 1];
            strcpy(cstr, inputFromFile.c_str());
            receiverMessage[i] = cstr;
        }
        receiverPacketsFile.close();
        Merkle_Tree verification(1);
        unsigned long long int *hashArray2 = verification.createMerkleTree(receiverMessage,splitSize);
        unsigned long long int chkHash = verification.getMasterRoot();
        if(chkHash == masterHash)
        {
            cout<<endl<<"Congrats, The message is not Tampered"<<endl<<endl;
            cout<<"The Received message is: ";
            for(int i = 0; i < splitSize; i++)
            {
                for(int j = 0; j < packetSize ; j++)
                {
                    if(receiverMessage[i][j] != '$')
                        cout<<receiverMessage[i][j];
                }
            }
            cout<<endl;
        }
        else
        {
            cout<<endl<<"Oops,The message has been Tampered"<<endl<<endl;
            cout<<"The Received message is: ";
            for(int i = 0; i < splitSize; i++)
            {
                for(int j = 0; j < packetSize ; j++)
                {
                    if(receiverMessage[i][j] != '$')
                        cout<<receiverMessage[i][j];
                }
            }
            cout<<endl;
            for(int i = (2*splitSize)  ; i >=1 ; i--)
            {
                if( hashArray2[i] != hashArray[i] )
                {
                    cout<<"Tampered Nodes: "<<i<<endl;
                }
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"The Program is Terminated"<<endl;
    }
    return 0;
}

// The following function splits the given input string according to the required packet size.
char** stringProcess(string inputString, int splitSize)
{
    int length = inputString.length();
    char** msgPackets = new char* [splitSize];
    if(length%splitSize == 0)
    {
        packetSize = ( (inputString.length()) / splitSize );
        for(int i = 0; i < splitSize ; i++)
        {
            char *temp = new char [ packetSize + 1];
            for(int j = 0; j < packetSize ;j++)
            {
                temp[j] = inputString[j];
            }
            temp[packetSize] = '\0';
            inputString.erase(inputString.begin(), inputString.begin() + packetSize);
            msgPackets[i] = temp;
        }
    }
    else
    {
        int parityAdder = splitSize - (length % splitSize);                     // Adding Parity bit for meeting the size requirements.
        for(int i=1; i<= parityAdder; i++)
        {
            inputString += "$";
        }
        packetSize = (inputString.length()) / splitSize;
        for(int i = 0; i < splitSize ; i++)
        {
            char *temp = new char [ packetSize + 1];
            for(int j = 0; j < packetSize ;j++)
            {
                temp[j] = inputString[j];
            }
            temp[packetSize] = '\0';
            inputString.erase(inputString.begin(), inputString.begin() + packetSize);
            msgPackets[i] = temp;
        }
    }
    return msgPackets;
}
