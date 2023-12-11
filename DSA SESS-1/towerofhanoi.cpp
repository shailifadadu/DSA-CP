//Tower of hanoi
//only 1 disk transferred in 1 step
//smaller disks are always kept on top of larger disks

#include<iostream>
#include<string>
using namespace std;
class Hanoi
{
  public:
  void towerOfHanoi(int n, string src, string help, string dest);
};

void Hanoi:: towerOfHanoi(int n, string src, string help, string dest)
{
  if(n==1)
  {
    cout<<"transfer disk "<<n<<" from "<<src <<" to "<<dest<<endl;
    return;
  }
  towerOfHanoi(n-1,src,dest,help);
  cout<<"transfer disk "<<n<<" from "<<src <<" to "<<dest<<endl;
  towerOfHanoi(n-1,help,src,dest);
}

int main()
{
  int n=3;
  Hanoi h;
  h.towerOfHanoi(n, "S", "H", "D");
  return 0;
}
