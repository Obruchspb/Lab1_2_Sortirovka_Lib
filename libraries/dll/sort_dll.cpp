#include "sort_dll.hpp"

__declspec(dllexport) void Func_Fast_Sort(std::vector<int> *RefVector, int LeftBoard, int RightBoard)
{
  int Pivot; // разрешающий элемент
  int LeftHold = LeftBoard; //левая граница
  int RightHold = RightBoard; // правая граница
  Pivot = (*RefVector)[LeftBoard];
  while (LeftBoard < RightBoard) // пока границы не сомкнутся
  {
    while (((*RefVector)[RightBoard] >= Pivot) && (LeftBoard < RightBoard))
      RightBoard--; // сдвигаем правую границу пока элемент [RightBoard] больше [Pivot]
    if (LeftBoard != RightBoard) // если границы не сомкнулись
    {
		(*RefVector)[LeftBoard] = (*RefVector)[RightBoard]; // перемещаем элемент [RightBoard] на место разрешающего
      LeftBoard++; // сдвигаем левую границу вправо 
    }
    while (((*RefVector)[LeftBoard] <= Pivot) && (LeftBoard < RightBoard))
      LeftBoard++; // сдвигаем левую границу пока элемент [LeftBoard] меньше [Pivot]
    if (LeftBoard != RightBoard) // если границы не сомкнулись
    {
		(*RefVector)[RightBoard] = (*RefVector)[LeftBoard]; // перемещаем элемент [LeftBoard] на место [RightBoard]
      RightBoard--; // сдвигаем правую границу вправо 
    }
  }
  (*RefVector)[LeftBoard] = Pivot; // ставим разрешающий элемент на место
  Pivot = LeftBoard;
  LeftBoard = LeftHold;
  RightBoard = RightHold;
  if (LeftBoard < Pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
	  Func_Fast_Sort(RefVector, LeftBoard, Pivot - 1);
  if (RightBoard > Pivot)
	  Func_Fast_Sort(RefVector, Pivot + 1, RightBoard);
}
