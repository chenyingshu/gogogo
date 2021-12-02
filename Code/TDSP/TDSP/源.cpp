
/*TSP�������̰�ķ�������ڵ����*/
/*
	TSP������ָ���м���Ҫ����n�����У�Ҫ��������о����ҽ�����һ�Σ�
	Ȼ��ص��������У��������ߵ�·����̡�
*/
/*
	����ڵ���ԣ���������г�����ÿ����û�е����ĳ�����ѡ�������һ����
	ֱ�����������еĳ��У����ص���������
*/

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
//��TSP
class TSP
{
private:
	int city_number;	//���и���
	double** time;		//���о������
	double** cost;		//���о������
	double** calorie;		//���о������
	double** total_cost; //�ܵ�cost����
	int start;		//������
	int* flag;		//��־���飬�жϳ����Ƿ���뺺�ܶٻ�·
	double TSPLength;		//·������
	double weight_time; //ʱ���Ȩ��
	double weight_cost; //������Ȩ��
	double weight_calorie; //calorie��Ȩ��
public:
	TSP(int city_num);	//���캯��
	void correct();		//�����û�����ĳ��о������
	void printCity();       //����û�����ĳ��о���
	void TSP1();		//̰�ķ�������ڵ����������������
};

//���캯��
TSP::TSP(int city_num)
{
	int i = 0, j = 0;
	int start_city;
	city_number = city_num;

	//��ʼ�����
	cout << "Please enter the city starting point of this operation. The range is:" << 0 << "-" << city_number - 1 << endl;
	cin >> start_city;
	start = start_city;

	//Ȩ��
	cout << "Please enter the weight for time:" << endl;
	cin >> weight_time;
	cout << "Please enter the weight for cost:" << endl;
	cin >> weight_cost;
	cout << "Please enter the weight for Calorie" << endl;
	cin >> weight_calorie;


	//��ʼ�����о������
	time = new double* [city_number];
	cost = new double* [city_number];
	calorie = new double* [city_number];
	total_cost = new double* [city_number];
	cout << "Please enter the traffic time between " << city_number << " cities" << endl;
	for (i = 0; i < city_number; i++)
	{
		time[i] = new double[city_number];
		for (j = 0; j < city_number; j++) {
			cin >> time[i][j];
			time[i][j] = weight_time * time[i][j];
		}		
	}
	cout << "Please enter the traffic cost between " << city_number << " cities" << endl;
	for (i = 0; i < city_number; i++)
	{
		cost[i] = new double[city_number];
		for (j = 0; j < city_number; j++) {
			cin >> cost[i][j];
			cost[i][j] = weight_cost * cost[i][j];
		}
			
	}
	cout << "Please enter the Calorie between " << city_number << " cities" << endl;
	for (i = 0; i < city_number; i++)
	{
		calorie[i] = new double[city_number];
		for (j = 0; j < city_number; j++) {
			cin >> calorie[i][j];
			calorie[i][j] = weight_calorie * calorie[i][j];
		}
			
	}

	for (i = 0; i < city_number; i++)
	{
		total_cost[i] = new double[city_num];
		for (j = 0; j < city_num; j++) {
			total_cost[i][j] = time[i][j] + cost[i][j] + calorie[i][j];
		}
	}
	//��ʼ����־����
	flag = new int[city_number];
	for (i = 0; i < city_number; i++)
	{
		flag[i] = 0;
	}

	TSPLength = 0;

}

//�����û�����ĳ��д��۾���
void TSP::correct()
{
	int i;
	for (i = 0; i < city_number; i++)
	{
		total_cost[i][i] = 0;
	}
}

//��ӡ���о���
void TSP::printCity()
{
	int i, j;
	//��ӡ���۾���
	cout << "The traffic time you entered is as follows:" << endl;
	for (i = 0; i < city_number; i++)
	{
		for (j = 0; j < city_number; j++)
			cout << setw(7) << total_cost[i][j];
		cout << endl;
	}
}


//̰�ķ�������ڵ����������������
void TSP::TSP1()
{
	int edgeCount = 0;
	double min;
	int j;
	int start_city = start;	//������
	int next_city;			//��һ������
	flag[start] = 1;
	cout << "Path as follows:" << endl;
	while (edgeCount < city_number - 1)//ѭ��ֱ����������city_number-1
	{
		min = 10000;
		for (j = 0; j < city_number; j++)//��ǰ����������Сֵ
		{
			if ((flag[j] == 0) && (total_cost[start_city][j] != 0) && (total_cost[start_city][j] < min))
			{
				next_city = j;
				min = total_cost[start_city][j];
			}
		}
		TSPLength += total_cost[start_city][next_city];
		flag[next_city] = 1;//��������뺺�ܶ��ٻ�·
		edgeCount++;
		cout << start_city << "-->" << next_city << endl;

		start_city = next_city;//��һ�δ�next_city����
	}

	cout << next_city << "-->" << start << endl;//���Ļر�
	TSPLength += total_cost[start_city][start];
	cout << "The path length is:" << TSPLength;//���ܶ��ٻ�·�ĳ���

}


//������
int main()
{
	cout << "Welcome to the greedy method of nearest neighbor strategy to find travel salesman problem, please enter the number of cities:";
	int city_number;
	while (cin >> city_number)
	{
		TSP tsp(city_number);	//��ʼ��
		tsp.correct();			   //��������ĳ��о������
		tsp.printCity();		   //��ӡ����ĳ���
		tsp.TSP1();			   //���
		cout << "-------------------------------------------------------" << endl;
		cout << "\nWelcome to the greedy method of nearest neighbor strategy to find travel salesman problem, please enter the number of cities:";
	}

	return 0;
}