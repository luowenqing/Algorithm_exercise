#include <iostream>
#include <vector>
#include <map>
#define MaxFirst 3
#define MaxSecond 5
#define MaxThird 8
using namespace std;
 
class State
{
public:
	int second;
	int num[3];
	State* preState;
        static map<int,int> mapping;
 
public:
	State(int first,int second,int third)
	{
		num[0]=first;
		num[1]=second;
		num[2]=third;	
	}
	void init()
	{		
		mapping[0]=MaxFirst;
		mapping[1]=MaxSecond;
		mapping[2]=MaxThird;
	}
 
	bool canPour(int from,int to)//�ж��Ƿ���Դ�fromˮ���е�ˮ��toˮ����
	{
		if(num[from]==0)
		{
			return false;
		}
 
		if(num[to]==mapping[to])
		{
			return false;
		}
		else 
		{
			return true;
		}
	}
	void pour(int from,int to)//��ˮ����
	{
		if(num[from]+num[to]>mapping[to])
		{
			num[from]=num[from]-(mapping[to]-num[to]);
			num[to]=mapping[to];
		}
		else
		{
			num[to]=num[to]+num[from];
			num[from]=0;
		}
	}
 
};
map<int,int> State::mapping;
 
int main()
{
	map<int,int> states;
	State *start=new State(0,0,8);
	start->init();
	State *state=start;
	State *endState=new State(8,8,8);//ֻ�л�ý�endState�Ż�ı䣬��ֵȫΪ8Ϊ�˷����ж��Ƿ������ս�
	vector<State> action;//��������״̬����
	action.push_back(*start);//�ѳ�ʼ״̬�ȼ��������
	int n=0;
	do{
		for(int i=0;i<3;i++)//˫��ѭ��Ϊ��iˮ���е�ˮ��jˮ����
		{
			for(int j=0;j<3;j++)
			{
				if(i!=j)
				{
					if(state->canPour(i,j))
					{
						state->pour(i,j);
						if(states[state->num[0]*100+state->num[1]*10+state->num[2]]==0)//�����״̬����hash���У���Ϊ��һ�γ��ָ�״̬
						{
							states[state->num[0]*100+state->num[1]*10+state->num[2]]++;
							(state->preState)=new State(action[n]);
							action.push_back(*state);
							if(state->num[0]==4||state->num[1]==4||state->num[2]==4)//��ý�
							{
								endState=state;
								i=4;
								break;	
							}
					    }
					}
				}
				*state=action[n];
			}			
		}
		n++;
	}while(endState->num[0]==8&&endState->num[1]==8&& n<action.size());
	cout<<endState->num[0]<<" "<<endState->num[1]<<" "<<endState->num[2]<<endl;
	state=endState;
	do
	{
		state=state->preState;
		cout<<state->num[0]<<" "<<state->num[1]<<" "<<state->num[2]<<endl;		
	}while(state->num[2]!=8);
	return 0;
}

