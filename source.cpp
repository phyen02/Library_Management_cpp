#include <iostream>
#include <iomanip>  
#include <fstream>  
#include <conio.h>  
#include <string.h>
#include <stdio.h>   
#include <cstdlib> 
#include <windows.h>
#include <time.h>
#include <vector> 
using namespace std;
//////////////////////////////////////////////////
//				   	GOTOXY						//
//////////////////////////////////////////////////
void gotoxy(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//////////////////////////////////////////////////
//   			SET FONT COLOR					//
//////////////////////////////////////////////////
void SET_COLOR(int color)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

//Tao class sach
class Book {
	//tinh dong goi trong huong doi tuong 
	private:
		string sid,stitle,sAuthor,sCategory; //private variables
		int nPubYear,nsl;
	public:
		void add();
		void in();
		string getid(){return sid;}
		string getTitle(){return stitle;}
		string getAuthor(){return sAuthor;}
		string getCategory(){return sCategory;}
		int getYear(){return nPubYear;}
		int getsl(){return nsl;}
		//ham tao 
		Book(){
			this->sid="null";
			this->stitle="null";
			this->sAuthor="null";
			this->sCategory="null";
			this->nPubYear=0;
			this->nsl=0; 
		}
		//ham huy
		~Book(){
		}
	};
	//nhap thong tin sach
	void Book::add(){
		cout<<"\n\nNhap Ten Sach: ";
		fflush(stdin); 
		getline(cin,stitle);
		cout<<"\nNhap ID Sach: ";
		fflush(stdin);
		getline(cin,sid);
		cout<<"\nNhap Ten Tac Gia: ";
		fflush(stdin);
		getline(cin,sAuthor);
		cout<<"\nNhap Nam Xuat Ban: ";
		cin>>nPubYear;
		cout<<"\nNhap The Loai: ";
		fflush(stdin);
		getline(cin,sCategory);
		cout<<"\nNhap So Luong: ";
		cin>>nsl;
	}
	//xuat thong tin sach
void Book::in(){
	SET_COLOR(4);
	cout << "________________________________________________________________________________________________________________________________________________________________" << endl;
	SET_COLOR(5);
	cout << setw(8) << sid << setw(31) << stitle << setw(30) << sAuthor << setw(25) << nPubYear << setw(30) << sCategory << setw(34) << nsl << endl;
	SET_COLOR(4);
	cout << "________________________________________________________________________________________________________________________________________________________________" << endl;
}
//nhap danh sach sach
class thuvien{
	private :
			vector<Book *> B;
			int n;
	public:
		void adddanhsach();
		void indanhsach();
		void timkiemten();
		void timkiemID();
		void timkiemNXB();
		void timkiemTL();
		void timkiemTG();
		void themsach();
		void SapXepSoLuongSachTangDan();
		void sapxeptheotensach();
		void SapXepSoLuongSachGiamDan();
		void sapxeptheoNXBtangdan();
		void sapxeptheoNXBgiamdan();
		void sapxeptheotenTG();
		void sapxeptheotheloai();
		void suadoi_1_tuong();
		void suadoitoanbo();
		int tongsosach();
		void xoasachtheoten();
		void xoasachtheoID();
		void xoasachtheoNXB();
		void xoasachtheoTL();
		void xoasachtheoTG();
		int TimKiem();
		int SapXep();
		int Sua();
		int xoasach();
};

void thuvien::adddanhsach(){
	system("cls");
	fflush(stdin);
	SET_COLOR(4);
	cout<<"\nNhap So Loai Sach Ban Muon Quan Ly: ";
	cin>>this->n;
	fflush(stdin);
    Book *tv;
	for(int i=0;i<this->n;i++){
		system("cls");
		cout << "\t\t----------NHAP THONG TIN SACH---------" << endl << endl;
		SET_COLOR(5);
		cout<<"\nNhap Thong Tin Sach Thu "<<i+1<<":";
        tv=new Book;
        tv->add();
		B.push_back(tv);
		Sleep(600);
        SET_COLOR(4);
        cout << "\n\nSACH DA DUOC THEM..." << endl;
		Sleep(300);
		ofstream saveSach("sach.bin", ios :: binary | ios :: app);
        saveSach.write((char*)(&B), sizeof(Book));
        saveSach.close();

	}
}

//in danh sach sach
void thuvien::indanhsach(){
    system("cls");
    SET_COLOR(4);
    cout << "\t\t----------DANH SACH SACH TRONG THU VIEN---------" << endl << endl;
	cout << "__________" << "______________________________" << "______________________________" << "______________________________" << "______________________________" << "______________________________" << endl;
	SET_COLOR(5);
	cout<<setw(10)<<"\"ID\""<<setw(30)<<"\"Ten sach\""<<setw(30)<<"\"Tac gia\""<<setw(30)<<"\"Nam Xuat Ban\""<<setw(30)<<"\"The Loai\""<<setw(30)<<"\"So Luong\""<<endl;
	SET_COLOR(4);
	cout << "__________" << "______________________________" << "______________________________" << "______________________________" << "______________________________" << "______________________________" << endl;
	ifstream printSach("sach.bin", ios :: binary);
	if(!printSach)
	{
		cout << "\n\t\tLoi doc du lieu" << endl;
	} else {
		for(int i=0;i<this->n;i++)
		{
				SET_COLOR(5);
				cout<<"\nQuyen Sach Thu "<<i+1<<":" << endl;
				SET_COLOR(4);
				cout << "______________________________" << endl;
				this->B.at(i)->in();
		}
	}
	printSach.close();
}

//ham tim kiem theo ten
void thuvien::timkiemten(){
	system("cls");
	int j=0;
	string ten;
	cout<<"\nNhap ten sach ban muon tim: ";
	fflush(stdin);
	getline(cin,ten);
	//cau truc du lieu: thuat toan so sanh
    for(int i=0;i<this->n;i++){
    	if(B.at(i)->getTitle()==ten){
			system("cls");
			SET_COLOR(4);
			cout << "__________" << "______________________________" << "______________________________" << "______________________________" << "______________________________" << "______________________________" << endl;
			SET_COLOR(5);
			cout<<setw(10)<<"\"ID\""<<setw(30)<<"\"Tua sach\""<<setw(30)<<"\"Tac gia\""<<setw(30)<<"\"Nam Xuat Ban\""<<setw(30)<<"\"The Loai\""<<setw(30)<<"\"So Luong\""<<endl;
			B.at(i)->in();
    		j=j+1;
		}
	}
	if(j<=0){
		cout<<"\n\n\t\tTrong thu vien khong co sach nay!!!!";
	}
}

//ham tim kiem theo ID
void thuvien::timkiemID(){
	system("cls");
	int j=0;
	string ID;
	cout<<"\nNhap ID sach ban muon tim: ";
	fflush(stdin);
	getline(cin,ID);
    for(int i=0;i<this->n;i++){
		system("cls");
    	if(B.at(i)->getid()==ID){
			system("cls");
			SET_COLOR(4);
			cout << "__________" << "______________________________" << "______________________________" << "______________________________" << "______________________________" << "______________________________" << endl;
			SET_COLOR(5);
			cout<<setw(10)<<"\"ID\""<<setw(30)<<"\"Tua sach\""<<setw(30)<<"\"Tac gia\""<<setw(30)<<"\"Nam Xuat Ban\""<<setw(30)<<"\"The Loai\""<<setw(30)<<"\"So Luong\""<<endl;
    		B.at(i)->in();
    		j=j+1;
		}
	}
	if(j<=0){
		cout<<"\n\n\t\tTrong thu vien khong co sach nay!!!!";
	}  	
}

//ham tim kiem theo nam xuat ban
void thuvien::timkiemNXB(){
	system("cls");
	int j=0;
	int NXB;
	cout<<"\nNhap nam xuat ban cua sach ban muon tim: ";
	fflush(stdin);
	cin>>NXB;
    for(int i=0;i<this->n;i++){
    	if(B.at(i)->getYear()==NXB){
			system("cls");
			SET_COLOR(4);
			cout << "__________" << "______________________________" << "______________________________" << "______________________________" << "______________________________" << "______________________________" << endl;
			SET_COLOR(5);
			cout<<setw(10)<<"\"ID\""<<setw(30)<<"\"Tua sach\""<<setw(30)<<"\"Tac gia\""<<setw(30)<<"\"Nam Xuat Ban\""<<setw(30)<<"\"The Loai\""<<setw(30)<<"\"So Luong\""<<endl;
    		B.at(i)->in();
    		j=j+1;
		}
	}
	if(j<=0){
		cout<<"\n\n\t\tTrong thu vien khong co sach nay!!!!";
	}  	
}

void thuvien::timkiemTL(){
	system("cls");
	int j=0;
	string TL;
	cout<<"\nNhap the loai sach ban muon tim: ";
	fflush(stdin);
	getline(cin,TL);
    for(int i=0;i<this->n;i++){
    	if(B.at(i)->getCategory()==TL){
			system("cls");
			SET_COLOR(4);
			cout << "__________" << "______________________________" << "______________________________" << "______________________________" << "______________________________" << "______________________________" << endl;
			SET_COLOR(5);
			cout<<setw(10)<<"\"ID\""<<setw(30)<<"\"Tua sach\""<<setw(30)<<"\"Tac gia\""<<setw(30)<<"\"Nam Xuat Ban\""<<setw(30)<<"\"The Loai\""<<setw(30)<<"\"So Luong\""<<endl;
    		B.at(i)->in();
    		j=j+1;
		}
	}
	if(j<=0){
		cout<<"\n\n\t\tTrong thu vien khong co sach nay!!!!";
	}  
}

void thuvien::timkiemTG(){
	system("cls");
	int j=0;
	string TG;
	cout<<"\nNhap ten tac gia sach ban muon tim: ";
	fflush(stdin);
	getline(cin,TG);
    for(int i=0;i<this->n;i++){
    	if(B.at(i)->getAuthor()==TG){
			system("cls");
			SET_COLOR(4);
			cout << "__________" << "______________________________" << "______________________________" << "______________________________" << "______________________________" << "______________________________" << endl;
			SET_COLOR(5);
			cout<<setw(10)<<"\"ID\""<<setw(30)<<"\"Tua sach\""<<setw(30)<<"\"Tac gia\""<<setw(30)<<"\"Nam Xuat Ban\""<<setw(30)<<"\"The Loai\""<<setw(30)<<"\"So Luong\""<<endl;
    		B.at(i)->in();
    		j=j+1;
		}
	}
	if(j<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
	} 
}

//ham them sach 
//con tro (mang dong)
 void thuvien::themsach(){
	this->n++;
    Book *m;
    m=new Book;
	system("cls");
	m->add();
    B.push_back(m);
} 

void thuvien::SapXepSoLuongSachTangDan(){
	system("cls");
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(B.at(i)->getsl()>B.at(j)->getsl()){
				Book *temp= B.at(i);
				B.at(i) = B.at(j);
				B.at(j)= temp;
			}
		}
	}
	indanhsach(); 
}

void thuvien::sapxeptheotensach(){
	system("cls");
	for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
         if(B.at(i)->getTitle()>B.at(j)->getTitle()){
         	Book *temp= B.at(i);
				B.at(i) = B.at(j);
				B.at(j)= temp;
         }
      }
      indanhsach();
} 

void thuvien::SapXepSoLuongSachGiamDan(){
	system("cls");
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(B.at(i)->getsl()<B.at(j)->getsl()){
				Book *temp= B.at(i);
				B.at(i) = B.at(j);
				B.at(j)= temp;
			}
		}
	}
	indanhsach();
}

void thuvien::sapxeptheoNXBtangdan(){
	system("cls");
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(B.at(i)->getYear()>B.at(j)->getYear()){
				Book *temp= B.at(i);
				B.at(i) = B.at(j);
				B.at(j)= temp;
			}
		}
	}
	indanhsach();
}

void thuvien::sapxeptheoNXBgiamdan(){
	system("cls");
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(B.at(i)->getYear()<B.at(j)->getYear()){
				Book *temp= B.at(i);
				B.at(i) = B.at(j);
				B.at(j)= temp;
			}
		}
	}
	indanhsach();
}

void thuvien::sapxeptheotenTG(){
	system("cls");
	for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
         if(B.at(i)->getAuthor()>B.at(j)->getAuthor()){
         	Book *temp= B.at(i);
				B.at(i) = B.at(j);
				B.at(j)= temp;
         }
      }
      indanhsach();
}

void thuvien::sapxeptheotheloai(){
	system("cls");
	for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
         if(B.at(i)->getCategory()>B.at(j)->getCategory()){
         	Book *temp= B.at(i);
				B.at(i) = B.at(j);
				B.at(j)= temp;
         }
      }
      indanhsach();
}

void thuvien::suadoi_1_tuong(){
	system("cls");
	int j=0;
	string TS;
	cout<<"\nNhap ten sach ban muon sua thong tin: ";
	fflush(stdin);
	getline(cin,TS);
	for(int i=0;i<n;i++){
		if(B.at(i)->getTitle()==TS){
			system("cls");
			Book *t=new Book;
			t->add() ;
			B.at(i) =t;
			j++;
			cout << "Sua thong tin thanh cong";
		}
	}
	if(j<=0) cout<<"\n\n\t\tTrong Thu Vien Khong Co Sach Nay!!!";
}

void thuvien::suadoitoanbo(){
	system("cls");
	int m;
	cout<<"\nNhap so loai sach ban muon quan ly:";
	cin>>m;
	this->n=m;
	system("cls");
	system("cls");
	adddanhsach();
	cout << "Sua thong tin thanh cong"; 
}

int thuvien::tongsosach(){
	int ts=0;
	for(int i=0;i<n;i++){
		ts+=B.at(i)->getsl();
	}
	return ts;
}

void thuvien::xoasachtheoten(){
	system("cls");
	string TS;
	cout<<"Nhap ten sach ban muon xoa: ";
	fflush(stdin);
	getline(cin,TS);
	int k=0;
	for(int i=0; i<n ; i++){
		if(B.at(i)->getTitle()==TS){
		    for(int j=i; j<n; j++){
				B.at(i) = B.at(j);
			}
			B.pop_back();
            n--;
            k++;
			cout << endl << endl << endl;
            cout<<"Da xoa thanh cong!!!";
		}
	}
    if(k<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
	} 
}

void thuvien::xoasachtheoID(){
	system("cls");
	string TS;
	cout<<"\nNhap ID sach ban muon xoa: ";
	fflush(stdin);
	getline(cin,TS);
    int k=0;
	for(int i=0; i<n ; i++){
		if(B.at(i)->getid()==TS){
			for(int j=i; j<n; j++){
				B.at(i) = B.at(j);
			}
			B.pop_back();
            n--;
            k++;
            cout<<"\n\n\nDa xoa thanh cong!!!";
		}
	}
    if(k<=0){
		cout<<"\n\n\nTrong thu vien khong co sach nay!!!!";
	}
}
void thuvien::xoasachtheoNXB(){
	system("cls");
	int TS;
	cout<<"\nNhap nam xuat ban sach ban muon xoa: ";
	cin>>TS;
     int k=0;
	for(int i=0; i<n ; i++){
		if(B.at(i)->getYear()==TS){
			for(int j=i; j<n; j++){
				B.at(i) = B.at(j);
			}
			B.pop_back();
            n--;
            k++;
            cout<<"\n\n\nDa xoa thanh cong!!!";
		}
	}if(k<=0){
		cout<<"\n\n\ntrong thu vien khong co sach nay!!!!";
	}

}
void thuvien::xoasachtheoTL(){
	system("cls");
	string TS;
	cout<<"\nNhap the loai sach ban muon xoa: ";
	fflush(stdin);
	getline(cin,TS);
    int k=0;
	for(int i=0; i<n ; i++){
		if(B.at(i)->getCategory()==TS){
			for(int j=i; j<n; j++){
				B.at(i) = B.at(j);
			}
			B.pop_back();
            n--;
            k++;
            cout<<"\n\n\nDa xoa thanh cong!!!";
		}
	}if(k<=0){
		cout<<"\n\n\nTrong thu vien khong co sach nay!!!!";
	}
}
void thuvien::xoasachtheoTG(){
	system("cls");
	string TS;
	cout<<"\nNhap ten tac gia sach ban muon xoa: ";
	fflush(stdin);
	getline(cin,TS);
    int k=0;
	for(int i=0; i<n ; i++){
		if(B.at(i)->getAuthor()==TS){
			for(int j=i; j<n; j++){
				B.at(i) = B.at(j);
			}
			B.pop_back();
            n--;
            k++;
            cout<<"\n\n\nDa xoa thanh cong!!!";
		}
	}if(k<=0){
		cout<<"\n\n\nTrong thu vien khong co sach nay!!!!";
	}
}
class thedocgia{
	protected:
		float gia; 
		string HoTen;
		int ngay,thang,nam;
		int HieuLuc;
	public:
	virtual float tinhtienlamthe() = 0;
	virtual void nhap(){
	SET_COLOR(5);
	cout<<"\nNhap Ho Ten The Doc Gia: ";
	fflush(stdin);
	getline(cin,HoTen);
	cout<<"\nNhap Ngay Thang Nam Ngay Tao The: ";
	cin>>ngay>>thang>>nam;
	cout<<"\nNhap So Thang Co Hieu Luc Cua The: ";
	cin>>HieuLuc;	
	}
	virtual void xuat(){
	SET_COLOR(5);
	cout<<"\nHo Ten The Doc Gia: "<<HoTen<<"\nNgay Tao The: "<<ngay<<"/"<<thang<<"/"<<nam;
	cout<<"\nSo Thang Co Hieu Luc: "<<HieuLuc;
	}
	thedocgia(){
		HoTen="null";
		ngay=0;
		thang=0;
		nam=0;
		HieuLuc=0;
	}
	~thedocgia(){
	}		
	
};

class DocGiaTreEm:public thedocgia{
    private:
 		string HoTenNDD;
 	public :
 		void nhap(){
 		thedocgia::nhap();
		cout<<"\nNhap Ho Ten Nguoi Dai Dien: ";
 		fflush(stdin);
 		getline(cin,HoTenNDD);	
 		}
 		void xuat(){
 		thedocgia::xuat();
 		cout<<"\nTen nguoi dai dien: "<<HoTenNDD;
          this->tinhtienlamthe(); 
        cout<<"\nSo tien lam the: "<<gia;
		}
 		float tinhtienlamthe(){
 			return gia=HieuLuc*5000;
		 }
};
class DocGiaNguoiLon:public thedocgia{
	private: 
	  string CMND;
	public:
		void nhap(){
			thedocgia::nhap();
			cout<<"\nNhap So Chung Minh Nhan Dan/ Can Cuoc Cong Dan: ";
			fflush(stdin);
			getline(cin,CMND);
		}
		void xuat(){
			thedocgia::xuat() ;
			cout<<"\nCMND/CCCD: "<<CMND;
            this->tinhtienlamthe(); 
            cout<<"\nSo tien lam the: "<<gia;	
		}
		float tinhtienlamthe(){
			return gia=HieuLuc*10000;
		}
};
class QLthedocgia{
	private:
		vector<thedocgia *> TD;
	public:
		void NhapDS(){
			system("cls");
            thedocgia *dg;
            int n,m;
			SET_COLOR(4);
            cout<<"Nhap so luong the doc gia tre em: ";
            cin>>n;
            for(int i=0;i<n;i++){ 
                dg=new DocGiaTreEm;
                dg->nhap();
                TD.push_back(dg);
                cout<<endl;
            }
			SET_COLOR(4);
            cout<<"Nhap so luong the doc gia nguoi lon: ";
            cin>>m;
            for(int i=0;i<m;i++){
                dg=new DocGiaNguoiLon;
                dg->nhap();
                TD.push_back(dg);
                cout<<endl;
            }
        }

        void XuatDS(){
			system("cls");
            cout << "-------Danh sach Doc Gia-------" << endl << endl;
            for(int i=0; i<this->TD.size();i++){
                this->TD.at(i)->xuat();
				SET_COLOR(4);
				cout << "\n----------";
                cout << endl;
            }
        }

        void SapXepTangDan(){
            for(int i=0;i<TD.size()-1;i++){
                for(int j=i+1;j<TD.size();j++){
                    if(TD.at(i)->tinhtienlamthe() > TD.at(j)->tinhtienlamthe()){
                        thedocgia *t= TD.at(i);
                        TD.at(i)=TD.at(j);
                        TD.at(j)=t;
                    }
                }
            }
            XuatDS();
        }
		
        void SapXepGiamDan(){
			system("cls");
            for(int i=0;i<TD.size()-1;i++){
                for(int j=i+1;j<TD.size();j++){
                    if(TD.at(i)->tinhtienlamthe() < TD.at(j)->tinhtienlamthe()){
                        thedocgia *t= TD.at(i);
                        TD.at(i)=TD.at(j);
                        TD.at(j)=t;
                    }
                }
            }
            XuatDS();
        }
        void TongTien(){
            float tong=0;
            for(int i=0;i<TD.size();i++){
                tong+=TD.at(i)->tinhtienlamthe();
            }
			system("cls");
            cout<<endl<<"--->Tong so tien lam the la : "<<setprecision(2)<<fixed<<tong<<endl;
        }
        
	
};
int thuvien::TimKiem(){
	int chon;
	system("cls");
	SET_COLOR(4);
	cout << setw( 70 ) << "------------------------------" << endl

      << setw( 70 ) << "| CHUONG TRINH TIM KIEM SACH |" << endl

      << setw( 70 ) << "------------------------------" << endl << endl;

	SET_COLOR(5);
	
	cout  << setw( 66 ) << "( 1 ) Tim Kiem Theo Ten Sach" << endl << endl

          << setw( 60 ) << "( 2 ) Tim Kiem Theo ID" << endl << endl

          << setw( 70 ) << "( 3 ) Tim Kiem Theo Nam Xuat Ban" << endl << endl

          << setw( 66 ) << "( 4 ) Tim Kiem Theo The Loai" << endl << endl

          << setw( 69 ) << "( 5 ) Tim Kiem Theo Ten Tac Gia" << endl << endl

          << setw( 69 ) << "( 6 ) Tro Ve Chuong Trinh Chinh" << endl << endl;
		  SET_COLOR(4);
	cout  << setw( 60 ) << "Nhap lua chon cua ban      [ ]" << endl << endl; 
			gotoxy(58,16); cin >> chon;
    switch(chon)
    {
            case 1:
                this->timkiemten();break;
            case 2:
				this->timkiemID();break;
            case 3:
                this->timkiemNXB();  break;
            case 4:
			  	this->timkiemTL();break;
            case 5:
			  	this->timkiemTG();break;
         	case 6: return 0;
            default: cout<<"\a";
       }
	return 0;
}
int thuvien::SapXep(){
	system("cls");
	int ch;
	SET_COLOR(4);
	cout << setw( 70 ) << "------------------------------" << endl

      << setw( 70 ) << "| CHUONG TRINH SAP XEP SACH |" << endl

      << setw( 70 ) << "------------------------------" << endl << endl;

	SET_COLOR(5);
	
	cout  << setw( 80 ) << "( 1 ) Sap Xep Theo So Luong Sach Tang Dan" << endl << endl

          << setw( 80 ) << "( 2 ) Sap Xep Theo So Luong Sach Giam Dan" << endl << endl

          << setw( 66 ) << "( 3 ) Sap Xep Theo Ten A->Z" << endl << endl

          << setw( 79 ) << "( 4 ) Sap Xep Theo Nam Xuat Ban Tang Dan" << endl << endl

          << setw( 79 ) << "( 5 ) Sap Xep Theo Nam Xuat Ban Giam Dan" << endl << endl

          << setw( 74 ) << "( 6 ) Sap Xep Theo Ten Tac Gia A->Z" << endl << endl

		  << setw( 66 ) << "( 7 ) Sap Xep Theo The Loai" << endl << endl

		  << setw( 70 ) << "( 8 ) Tro Ve Chuong Trinh Chinh" << endl << endl;

		  SET_COLOR(4);
	cout  << setw( 60 ) << "Nhap lua chon cua ban      [ ]" << endl << endl;
			gotoxy(58,20);
			cin >> ch;
    switch(ch)
    {
            case 1:
                this->SapXepSoLuongSachTangDan();break;
            case 2:
				this->SapXepSoLuongSachGiamDan ();break;
            case 3:
                this->sapxeptheotensach ();  break;
            case 4:
			  	this->sapxeptheoNXBtangdan();break;
            case 5:
			  	this->sapxeptheoNXBgiamdan();break;
			case 6:
			  	this->sapxeptheotenTG();break;  
			case 7:
			  	this->sapxeptheotheloai();break;	
        	case 8: return 0;
              	default:cout<<"\a";
       }
	return 0;
}

int thuvien::Sua(){
	system("cls");
	int choose;
	SET_COLOR(4);
	cout << setw( 70 ) << "-----------------------------------" << endl

      << setw( 70 ) << "| CHUONG TRINH SUA THONG TIN SACH |" << endl

      << setw( 70 ) << "-----------------------------------" << endl << endl;

	SET_COLOR(5);
	
	cout  << setw( 54 ) << "( 1 ) Sua 1 Cuon" << endl << endl

          << setw( 55 ) << "( 2 ) Sua Toan Bo" << endl << endl

          << setw( 69 ) << "( 3 ) Tro Ve Chuong Trinh Chinh" << endl << endl;
		  SET_COLOR(4);
	cout  << setw( 60 ) << "Nhap lua chon cua ban      [ ]" << endl << endl;
			gotoxy(58,10);
			cin >> choose;
    switch(choose)
    {
            case 1:
                this->suadoi_1_tuong();break;
            case 2:
				this->suadoitoanbo ();break;
            case 3: return 0;
              	default:cout<<"\a";
       }
	return 0;
}

int thuvien::xoasach(){
	system("cls");
	int ch1;
	SET_COLOR(4);
	cout << setw( 70 ) << "-------------------------" << endl

      << setw( 70 ) << "| CHUONG TRINH XOA SACH |" << endl

      << setw( 70 ) << "-------------------------" << endl << endl;

	SET_COLOR(5);
	
	cout  << setw( 66 ) << "( 1 ) Xoa Theo Ten Sach" << endl << endl

          << setw( 60 ) << "( 2 ) Xoa Theo ID" << endl << endl

          << setw( 70 ) << "( 3 ) Xoa Theo Nam Xuat Ban" << endl << endl

          << setw( 66 ) << "( 4 ) Xoa Theo The Loai" << endl << endl

          << setw( 69 ) << "( 5 ) Xoa Theo Ten Tac Gia" << endl << endl

          << setw( 74 ) << "( 6 ) Tro Ve Chuong Trinh Chinh" << endl << endl;
		  SET_COLOR(4);
	cout  << setw( 60 ) << "Nhap lua chon cua ban      [ ]" << endl << endl;
			gotoxy(58,16);
			cin >> ch1;
    switch(ch1)
    {
            case 1:
                this->xoasachtheoten();break;
            case 2:
				this->xoasachtheoID();break;
            case 3:
                this->xoasachtheoNXB();  break;
            case 4:
			  	this->xoasachtheoTL();break;
            case 5:
			  	this->xoasachtheoTG();break;
        	case 6: return 0;
              	default:cout<<"\a";
       }
	return 0;
}

int main(){
	//int n;
	//cin.ignore();
	//Book *B=new Book[n];
	thuvien b;
	QLthedocgia a;
	bool DaNhap = false;	
	bool thedoc = false;
	system("color Bf");
	while(true)
	{	system("cls");
	   	SET_COLOR(4);
		cout << setw( 70 ) << "--------------------------------" << endl

          << setw( 70 ) << "| CHUONG TRINH QUAN LY THU VIEN |" << endl

          << setw( 70 ) << "--------------------------------" << endl << endl;
		  SET_COLOR(6);
          cout << setw( 67 )

          << "HAY CHON CAC CHUC NANG SAU: "

          << endl << setw( 85 )

          << "--------------------------------------------------------------"

          << endl << endl;

		SET_COLOR(5);

    cout  << setw( 42 ) << "( N ) Nhap Danh sach Sach"

          << setw( 49 ) << "( A ) Nhap Danh Sach The Doc Sach" << endl << endl

          << setw( 36 ) << "( T ) Tim Kiem Sach"

          << setw( 50 ) << "( S ) Sap Xep Danh sach Sach" << endl << endl

          << setw( 31 ) << "( U ) Sua Sach"

          << setw( 41 ) << "( O ) Xoa Sach" << endl << endl
          
          << setw( 42 ) << "( X ) Xuat Danh sach Sach"

          << setw( 49 ) << "( D ) Xuat Danh Sach The Doc Sach" << endl << endl

		  << setw( 55 ) << "( G ) Tong So Cuon Sach Trong Thu Vien"

		  << setw( 38 ) << "( I ) Tong So Tien Lam The Doc Sach" << endl << endl

		  << setw( 75 ) << "( P ) Sap Xep Danh Sach The Doc Sach Theo So Tien Tang Dan" << endl << endl

		  << setw( 75 ) << "( E ) Sap Xep Danh Sach The Doc Sach Theo So Tien Giam Dan" << endl << endl

          << setw( 32 ) << "( H ) Them Sach"
		  
		  << setw( 50 ) << "( Q ) Thoat chuong trinh" << endl << endl;
		  SET_COLOR(4);
	cout  << setw( 50 ) << "Nhap lua chon cua ban      [ ]" << endl << endl;
			gotoxy(48,23);

		switch(getche()){
			case 'n':
			case 'N':
				b.adddanhsach();
				DaNhap=true;
				thedoc =true;
				cout<<"\nBam phim bat ky de tiep tuc!";
				getch();
				break;
			case 'x':
			case 'X':
				thedoc =true;
				if(DaNhap){
					b.indanhsach() ;
				} else{
					cout << endl << endl;
					cout << setw( 57 ) << "Ban chua nhap danh sach the doc !!!" << endl;
					}
            		cout << setw( 50 ) << "Bam phim bat ky de tiep tuc!";
				getch();
				break;
			case 't':
			case 'T':
				thedoc =true;
				if(DaNhap){
				b.TimKiem();
					} else{
					cout << endl << endl;
					cout << setw( 57 ) << "Ban chua nhap danh sach the doc !!!" << endl;
					}
					cout << endl << endl;
            		cout << setw( 50 ) << "Bam phim bat ky de tiep tuc!";
				getch();
				break;
			case 's':
			case 'S':
				thedoc =true;
				if(DaNhap){
					b.SapXep();	
				}else{
					cout << endl << endl;
					cout << setw( 57 ) << "Ban chua nhap danh sach the doc !!!" << endl;
					}
					cout << endl << endl;
            		cout << setw( 50 ) << "Bam phim bat ky de tiep tuc!";
				getch();
				break;
			case 'u':
			case 'U':
				thedoc =true;
				if(DaNhap){
				b.Sua (); 
				} else{
					cout << endl << endl;
					cout << setw( 57 ) << "Ban chua nhap danh sach the doc !!!" << endl;
					}
					cout << endl << endl;
            		cout << setw( 50 ) << "Bam phim bat ky de tiep tuc!";
				getch();
				break;
			case 'o':
			case 'O':
				thedoc =true;
				if(DaNhap){
				b.xoasach(); 	
				}else{
					cout << endl << endl;
					cout << setw( 57 ) << "Ban chua nhap danh sach the doc !!!" << endl;
					}
					cout << endl << endl;
            		cout << setw( 50 ) << "Bam phim bat ky de tiep tuc!";
				getch();
				break;
			case 'g':
			case 'G':
				thedoc =true;
				if(DaNhap){
					system("cls");
					cout<<"\n--> Tong so sach cua thu vien la: "<<b.tongsosach()<<"\n" ;
				} else{
					cout << endl << endl;
					cout << setw( 57 ) << "Ban chua nhap danh sach the doc !!!" << endl;
					}
				cout << endl << endl;
				cout << setw( 50 ) << "Bam phim bat ky de tiep tuc!";
				getch();
				break;
			case 'h':
			case 'H':
				thedoc =true;
				b.themsach();
				DaNhap=true;
				cout<<"\nBam phim bat ky de tiep tuc!";
				getch();
				break;
			case 'a':
			case 'A':
				thedoc =true;
				DaNhap=true;
				a.NhapDS();
				SET_COLOR(4);
				cout<<"\nBam phim bat ky de tiep tuc!";
                getch();
                break;
            case 'd':
			case 'D':
            	DaNhap=true;
            	if(thedoc){
            		a.XuatDS();
            	}else{
					cout << endl << endl;
					cout << setw( 57 ) << "Ban chua nhap danh sach the doc !!!" << endl;
					}
					cout << endl << endl;
					SET_COLOR(4);
            		cout << setw( 50 ) << "Bam phim bat ky de tiep tuc!";
                getch();
                break;
            case 'p':
			case 'P':
            	DaNhap=true;
            	if(thedoc){
					system("cls");
            		a.SapXepTangDan() ;
            	}else{
					cout << endl << endl;
					cout << setw( 57 ) << "Ban chua nhap danh sach the doc !!!" << endl;
					}
					cout << endl << endl;
            		cout << setw( 50 ) << "Bam phim bat ky de tiep tuc!";
                getch();
                break;
            case 'e':
			case 'E':
            	DaNhap=true;
            	if(thedoc){
            		a.SapXepGiamDan() ;
            	}else{
					cout << endl << endl;
					cout << setw( 57 ) << "Ban chua nhap danh sach the doc !!!" << endl;
					}
					cout << endl << endl;
            		cout << setw( 50 ) << "Bam phim bat ky de tiep tuc!";
                getch();
                break;
            case 'i':
			case 'I':
            	DaNhap=true;
            	if(thedoc){
            		a.TongTien() ;
            	}else{
					cout << endl << endl;
					cout << setw( 57 ) << "Ban chua nhap danh sach the doc !!!" << endl;
					}
					cout << endl << endl;
            		cout << setw( 50 ) << "Bam phim bat ky de tiep tuc!";
                getch();
                break;
			case 'q':
			case 'Q':
				cout << endl << endl;
                cout<< setw( 50 ) << "Ban da chon thoat chuong trinh!";
                getch();
                return 0;
            default:
				cout << endl << endl;
                cout << setw( 50 ) << "Khong co chuc nang nay!";
                getch();
                break;
		}		
	}
	getch();
}
