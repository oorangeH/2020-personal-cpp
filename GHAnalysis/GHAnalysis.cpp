// GHAnalysis.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>

/*int main()
{
    std::cout << "Hello World!\n";
}  */

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


#include <string>  
#include <json.h>
#include <iostream>  
#include <fstream>  

 
void readStrJson(); //从字符串中读取JSON  
void readStrProJson(); //从字符串中读取JSON（内容复杂些）  
void readFileJson(); //从文件中读取JSON 
void writeFileJson();  //将信息保存为JSON格式  
 
int main(int argc, char *argv[])
{
	int push=0;
	int pull=0;
	int comment=0;
	int issues=0;
	int push1=0;
	int pull1=0;
	int comment1=0;
	int issues1=0;
	
	writeFileJson(); //写入json
 
	readFileJson(); //从文件中读取JSON 
 
	cout << "\n\n";
 
	readStrJson();  //从字符串中读json
 
	cout << "\n\n";
 
	readStrProJson();//从字符串中读取JSON（内容复杂些）  
	
	system("pause");
	return 0;
 } 
 
 
 void readFileJson()
{
	Json::Reader reader;
	Json::Value root;
 
	//从文件中读取，保证当前文件有demo.json文件  
	ifstream in("2015-01-01-15(1).json", ios::binary);
 
	if (!in.is_open())
	{
		std::cout << "Error opening file\n";
		return;
	}
 
	if (reader.parse(in, root))
	{
		//读取根节点信息  
		string type = root["type"].asString();

		//读取子节点信息  
		int size = root["payload"]["size"].asInt();
 
        if(size==1)
        {  if(type[2]=='s')
              push+=1;
           if(type[2]=='l')
              pull+=1;
           if(type[5]=='C')
              comment+=1;
           if(type[5]=='s')
               issues+=1;
		}
		
		if(size>1)
		{  if(type[2]=='s')
              push1+=1;
           if(type[2]=='l')
              pull1+=1;
           if(type[5]=='C')
              comment1+=1;
           if(type[5]=='s')
               issues1+=1;
		}
			
		std::cout<<"The number of person's pushevent is "<<push<<endl;
		std::cout<<"The number of person's pullrequestevent is "<<pull<<endl;
		std::cout<<"The number of person's issuesevent is "<<issues<<endl;
		std::cout<<"The number of person's issuecommentevent is "<<comment<<endl;
		
		std::cout<<"The number of project's pushevent is "<<push1<<endl;
		std::cout<<"The number of project's pullrequestevent is "<<pull1<<endl;
		std::cout<<"The number of project's issuesevent is "<<issues1<<endl;
		std::cout<<"The number of project's issuecommentevent is "<<comment1<<endl;
	}
	else
	{
		std::cout << "parse error\n" << endl;
	}
 
	in.close();
}

