#include "Va.h"
#include "Va2-11.h"
using namespace std;
typedef int ElemType;

void show(ElemType &c)
{
      cout << c << " ";
}
int main()
{
      SqList L;
      ElemType e,e0;
      Status i;
      int j,k;
      i=InitList(L);
      printf("初始化L后：L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
    return 0;
}
