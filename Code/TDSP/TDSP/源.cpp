
/*TSP问题采用贪心法的最近邻点策略*/
/*
	TSP问题是指旅行家需要旅行n个城市，要求各个城市经过且仅经过一次，
	然后回到出发城市，并且所走的路径最短。
*/
/*
	最近邻点策略：从任意城市出发，每次在没有到过的城市中选择最近的一个，
	直到经过了所有的城市，最后回到出发城市
*/

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
//类TSP
class TSP
{
private:
	int city_number;	//城市个数
	double** time;		//城市距离矩阵
	double** cost;		//城市距离矩阵
	double** calorie;		//城市距离矩阵
	double** total_cost; //总的cost矩阵
	int start;		//出发点
	int* flag;		//标志数组，判断城市是否加入汉密顿回路
	double TSPLength;		//路径长度
	double weight_time; //时间的权重
	double weight_cost; //花销的权重
	double weight_calorie; //calorie的权重
public:
	TSP(int city_num);	//构造函数
	void correct();		//纠正用户输入的城市距离矩阵
	void printCity();       //输出用户输入的城市距离
	void TSP1();		//贪心法的最近邻点策略求旅行商问题
};

//构造函数
TSP::TSP(int city_num)
{
	int i = 0, j = 0;
	int start_city;
	city_number = city_num;

	//初始化起点
	cout << "Please enter the city starting point of this operation. The range is:" << 0 << "-" << city_number - 1 << endl;
	cin >> start_city;
	start = start_city;

	//权重
	cout << "Please enter the weight for time:" << endl;
	cin >> weight_time;
	cout << "Please enter the weight for cost:" << endl;
	cin >> weight_cost;
	cout << "Please enter the weight for Calorie" << endl;
	cin >> weight_calorie;


	//初始化城市距离矩阵
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
	//初始化标志数组
	flag = new int[city_number];
	for (i = 0; i < city_number; i++)
	{
		flag[i] = 0;
	}

	TSPLength = 0;

}

//纠正用户输入的城市代价矩阵
void TSP::correct()
{
	int i;
	for (i = 0; i < city_number; i++)
	{
		total_cost[i][i] = 0;
	}
}

//打印城市距离
void TSP::printCity()
{
	int i, j;
	//打印代价矩阵
	cout << "The traffic time you entered is as follows:" << endl;
	for (i = 0; i < city_number; i++)
	{
		for (j = 0; j < city_number; j++)
			cout << setw(7) << total_cost[i][j];
		cout << endl;
	}
}


//贪心法的最近邻点策略求旅行商问题
void TSP::TSP1()
{
	int edgeCount = 0;
	double min;
	int j;
	int start_city = start;	//起点城市
	int next_city;			//下一个城市
	flag[start] = 1;
	cout << "Path as follows:" << endl;
	while (edgeCount < city_number - 1)//循环直到边数等于city_number-1
	{
		min = 10000;
		for (j = 0; j < city_number; j++)//求当前距离矩阵的最小值
		{
			if ((flag[j] == 0) && (total_cost[start_city][j] != 0) && (total_cost[start_city][j] < min))
			{
				next_city = j;
				min = total_cost[start_city][j];
			}
		}
		TSPLength += total_cost[start_city][next_city];
		flag[next_city] = 1;//将顶点加入汉密尔顿回路
		edgeCount++;
		cout << start_city << "-->" << next_city << endl;

		start_city = next_city;//下一次从next_city出发
	}

	cout << next_city << "-->" << start << endl;//最后的回边
	TSPLength += total_cost[start_city][start];
	cout << "The path length is:" << TSPLength;//哈密尔顿回路的长度

}


//主函数
int main()
{
	cout << "Welcome to the greedy method of nearest neighbor strategy to find travel salesman problem, please enter the number of cities:";
	int city_number;
	while (cin >> city_number)
	{
		TSP tsp(city_number);	//初始化
		tsp.correct();			   //纠正输入的城市距离矩阵
		tsp.printCity();		   //打印输入的城市
		tsp.TSP1();			   //求解
		cout << "-------------------------------------------------------" << endl;
		cout << "\nWelcome to the greedy method of nearest neighbor strategy to find travel salesman problem, please enter the number of cities:";
	}

	return 0;
}