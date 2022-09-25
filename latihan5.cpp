#include <iostream>

using namespace std;
typedef int infotype;
typedef struct TelmtList *address;
typedef struct TelmtList
{
	infotype info;
	address next;
} ElmtList;

struct List
{
	address first = NULL;
};

void CreateEmpty(List *L)
{
	(*L).first = NULL;
}

bool IsEmpty(List L)
{
	cout << (L).first << endl;
	return ((L).first == NULL);
}

address Allocation(infotype x)
{
	address NewElmt;
	NewElmt = (ElmtList *)malloc(sizeof(ElmtList));
	NewElmt->info = x;
	NewElmt->next = NULL;

	return NewElmt;
}

void Deallocation(address hapus)
{
	free(hapus);
}

void InsertFirst(List *L, infotype x)
{
	address NewElmt;
	NewElmt = Allocation(x);

	if (NewElmt != NULL)
	{
		NewElmt->next = (*L).first;
		(*L).first = NewElmt;
	}
	cout << "Data masuk\n";
} //insert Data Pertama

void InsertAfter(address *PredElmt, infotype x)
{
	address NewElmt;
	NewElmt = Allocation(x);

	if (NewElmt != NULL)
	{
		NewElmt->next = (*PredElmt)->next;
		(*PredElmt)->next = NewElmt;
	}

} //memasukkan data diantara data yang sudah ada

void InsertLast(List *L, infotype x)
{
	if (IsEmpty(*L))
	{
		InsertFirst(&(*L), x);
	}
	else
	{
		address temp;
		temp = (*L).first;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		InsertAfter(&temp, x);
	}
} // memasukkan data pada bagian akhir

void DeleteFirst(List *L, infotype *hapus)
{
	if (!IsEmpty(*L))
	{
		address temp;
		temp = (*L).first;
		*hapus = temp->info;
		(*L).first = (*L).first->next;
		temp->next = NULL;
		Deallocation(temp);
	}
} //hapus data pertama

void DeleteAfter(address pred, infotype *hapus)
{
	if (pred->next != NULL)
	{
		address temp;
		temp = pred->next;
		*hapus = temp->info;
		pred->next = temp->next;
		temp->next = NULL;
		Deallocation(temp);
	}
} // hapus data diantara tengah data lainnya

void DeleteLast(List *L, infotype *hapus)
{
	if (!IsEmpty(*L))
	{
		address temp, predTemp;
		predTemp = NULL;
		temp = (*L).first;
		while (temp->next != NULL)
		{
			predTemp = temp;
			temp = temp->next;
		}
		if (temp == (*L).first)
		{
			DeleteFirst(&(*L), &(*hapus));
		}
		else
		{
			DeleteAfter(predTemp, &(*hapus));
		}
	}
}

int main()
{
	char pilihan;
	char out;
	infotype data;
	address temp;
	List listdata;
	do
	{
		cout << endl;
		cout << " ============================" << endl;
		cout << " =   PROGRAM LINKED LIST    =" << endl;
		cout << " ============================" << endl;
		cout << " = 1. Masukkan Data         =" << endl;
		cout << " = 2. Delete Data           =" << endl;
		cout << " = 3. Tampil Data           =" << endl;
		cout << " = 4. Exit                  =" << endl;
		cout << " ============================" << endl;
		cout << " Masukan Pilihan : ";
		cin >> pilihan;
		switch (pilihan)
		{
		case '1':
			system("cls");
			{
				cout << "\nMasukkan Data : ";
				cin >> data;
				temp = (listdata).first;
				if ((listdata).first == NULL)
				{
					address NewElmt;
					NewElmt = Allocation(data);
					if (NewElmt != NULL)
					{
						NewElmt->next = NULL;
						(listdata).first = NewElmt;
					}
					system("cls");
					break;
				}
				else
				{
					do
					{
						if (temp->info <= data)
						{
							if (temp->next == NULL)
							{
								address NewElmt;
								NewElmt = Allocation(data);

								if (NewElmt != NULL)
								{
									NewElmt->next = NULL;
									temp->next = NewElmt;
								}
								temp = temp->next;
								break;
							}
							else if ((temp->next)->info >= data)
							{
								address NewElmt;
								NewElmt = Allocation(data);

								if (NewElmt != NULL)
								{
									NewElmt->next = temp->next;
									temp->next = NewElmt;
								}
								temp = temp->next;
								break;
							}
							else
							{
								temp = temp->next;
							}
						}
						else if (temp->next == NULL)
						{
							address NewElmt;
							NewElmt = Allocation(data);

							if (NewElmt != NULL)
							{
								NewElmt->next = temp->next;
								temp->next = NewElmt;
							}
							temp = temp->next;
							break;
						}
						else
						{
							temp = temp->next;
						}
					} while (temp != NULL);
					break;
				}
				system("cls");
			}
		case '2':
			system("cls");
			{
				cout << "Masukkan Data Yang Ingin di hapus : ";
				cin >> data;
				temp = (listdata).first;
				if (temp->info == data)
				{
					int simpandata;
					DeleteFirst(&listdata, &simpandata);
				}
				else
				{
					do
					{
						if (temp->next == NULL)
						{
							cout << "Data yang ingin di hapus tidak ada" << endl;
							break;
						}
						else if ((temp->next)->info == data)
						{
							if ((temp->next)->next == NULL)
							{
								int simpandata;
								DeleteLast(&listdata, &simpandata);
								temp = temp->next;
								break;
							}
							else
							{
								int simpandata;
								DeleteAfter(temp, &simpandata);
								temp = temp->next;
								break;
							}
						}
						else
						{
							temp=temp->next;
						}
					} while (temp != NULL);
				}
				system("cls");
				break;
			}
		case '3':
			system("cls");
			{
				do
				{
					temp = (listdata).first;
					do
					{
						cout << "data linked list : " << temp->info << endl;
						temp = temp->next;

					} while (temp != NULL);					
					cout << "Masukkan 0 Jika Ingin kembali : ";
					cin >> out;
					switch  (out)
					{
					case '0': { break;
					} default:
						system("cls");
						{
							// operator is doesn't match any case constant (+, -, *, /)
							cout << "Masukkan Kembali Pilihan Anda"<<endl;
							break;
						}
					}
				} while (out != '0');
			}
			case '4' :
			system("cls");{
				cout<<"Terima Kasih";
				break;
			}
		default:
			system("cls");
			{
				// operator is doesn't match any case constant (+, -, *, /)
				cout << "Error! The operator is not correct";
				break;
			}
		}
	} while (pilihan != '4');
}