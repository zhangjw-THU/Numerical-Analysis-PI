#include<iostream>
#include<math.h>
#include"stdlib.h"
#include<iomanip>
using namespace std;

//////////////////////   PI   ////////////////////////////////

//����һ��̩��չ����PI
//����:N�����ȣ�
long double TaylarPi1(int N)
{
	long double Value = 0;
	long double InterationsNum  =1;
	long double RoundimgError = 0,MethodError = 0,Error =0;

	while(1)
	{
		RoundimgError = RoundimgError + 0.5*pow(10,-18);//�洢���
		MethodError = 4/(2*InterationsNum-1);//�������
		Error = RoundimgError + MethodError;
		if(Error<0.5*pow(10,-N))
		{
			break;
		}
		InterationsNum = InterationsNum +1;
	}

	cout<<setiosflags(ios::fixed)<<setprecision(0)<<"The number of iterations : "<<InterationsNum;
	
	for(int ii=1;ii<=InterationsNum;ii++)
	{
		Value = Value + 4*pow(-1,ii+1)/(2*ii-1);
	}
	return Value;
}

//���������Ľ���̩��չ����PI
//������N(���ȣ�
long double TaylarPi2(int N)
{
	long double Value = 0;
	long double InterationsNum  =1;
	long double RoundimgError = 0,MethodError = 0,Error =0;

	while (1)
	{
		RoundimgError = RoundimgError + 0.5*pow(10,-18);//�������
		MethodError = 2*sqrt(3)/((2*InterationsNum+1)*pow(3,InterationsNum));//�������
		Error = RoundimgError +MethodError;
		if(Error<0.5*pow(10,-N))
		{
			break;
		}
		InterationsNum = InterationsNum +1;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(0)<<"The number of iterations : "<<InterationsNum;
	for(int ii=1;ii<=InterationsNum;ii++)
	{
		Value = Value + 2*sqrt(3)*pow(-1,ii+1)/((2*ii-1)*pow(3,ii-1));
	}
	return Value;
}

//����������ֵ����֮���ι�ʽ��PI
//������N(���ȣ�
long double TrapezoidalPi(int N)
{
	long double Value;
	long double InterationsNum  =1;
	long double RoundimgError = 0,MethodError = 0,Error =0;

	while (1)
	{
		RoundimgError = InterationsNum*0.5*pow(10,-18);
		MethodError = 2/(3*InterationsNum*InterationsNum);
		Error = RoundimgError + MethodError;
		if(Error<0.5*pow(10,-N))
		{
			break;
		}
		InterationsNum = InterationsNum +1;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(0)<<"The number of iterations : "<<InterationsNum;
	long double h = 1/InterationsNum;
	Value = 4+2;
	for(long double ii=1;ii<InterationsNum;ii++)
	{
		Value = Value + 2*4/(1 + ii*h*ii*h);
	}
	Value = h*Value/2;
	return Value;
}


//////////////////////   Ln(PI)   ////////////////////////////////

//����һ���Ľ���̩��չ��
//������N�����ȣ���PI ����һ����õ�ֵ����NLast��PI�ľ��ȣ���
long double TaylarLnPi(int N,long double PI,int NLast)
{
	long double Value=0;
	long double InterationsNum  =1;
	long double RoundimgError = 0, MethodError = 0,LastError=0,Error = 0;
	long double Pitemp1 = (1+PI)/(PI-1);
	long double Pitemp2 = (PI-1)/(1+PI);

	while (1)
	{
		RoundimgError = InterationsNum*0.5*pow(10,-18);
		LastError = LastError + 2*pow(0.6,2*(InterationsNum-1));
		MethodError = 1/(4*(2*InterationsNum+1)*pow(Pitemp1,2*InterationsNum-1));
		Error = RoundimgError + LastError*0.5*pow(10,-NLast-1) + MethodError;
		if(Error<0.5*pow(10,-N))
		{
			break;
		}
		InterationsNum = InterationsNum +1;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(0)<<"The number of iterations : "<<InterationsNum;
	for(long double ii=1;ii<=InterationsNum;ii++)
	{
		Value = Value + 2*pow(Pitemp2,2*ii-1)/(2*ii-1);
	}
	return Value;

}

//�����������ι�ʽ��Ln(PI)
//������N�����ȣ���PI ����һ����õ�ֵ����NLast��PI�ľ��ȣ���
long double TrapezoidalLnPi(int N,long double PI,int NLast)
{
	long double Value=0;
	long double InterationsNum  =1;
	long double RoundimgError = 0,MethodError = 0,LastError=0,Error = 0;

	while (1)
	{
		RoundimgError = InterationsNum*0.5*pow(10,-18);
		LastError = 4*0.5*pow(10,-NLast);
		MethodError = 5/(3*InterationsNum*InterationsNum);
		Error = RoundimgError + LastError + MethodError;
		if(Error<0.5*pow(10,-N))
		{
			break;
		}
		InterationsNum = InterationsNum +1;
	}

	cout<<setiosflags(ios::fixed)<<setprecision(0)<<"The number of iterations : "<<InterationsNum;
	long double h = (PI-1)/InterationsNum;
	Value = 1+1/PI;
	for(long double ii=1;ii<InterationsNum;ii++)
	{
		Value = Value + 2/(1+ii*h);
	}
	Value = Value*h/2;
	return Value;
}

//����������������ʽ��Ln(PI)
//������N�����ȣ���PI ����һ����õ�ֵ����NLast��PI�ľ��ȣ���
long double SimpsonLnPi(int N,long double PI,int NLast)
{
	long double Value=0;
	long double InterationsNum  =1;
	long double RoundimgError = 0,MethodError = 0,LastError=0,Error = 0;

	while(1)
	{
		RoundimgError = 4*InterationsNum*0.5*pow(10,-18);
		LastError = 9*0.5*pow(10,-NLast);
		MethodError = 24*46/(2880*pow(InterationsNum,4));
		long double Error = RoundimgError + LastError + MethodError;
		if(Error<0.5*pow(10,-N))
		{
			break;
		}
		InterationsNum = InterationsNum+1;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(0)<<"The number of iterations : "<<InterationsNum;
	long double h = (PI-1)/InterationsNum;
	Value = 1 + 1/PI + 4/(1+h/2);//�˴�����
	for(long double ii=1;ii<InterationsNum;ii++)
	{
		Value = Value + 2/(1+ii*h) + 4/(1+ii*h+h/2);
	}
	Value = Value*h/6;
	return Value;
}

//////////////////////   PI^X   ////////////////////////////////

//����һ��̩��չ��
//������N�����ȣ���LnPI ����һ����õ�ֵ����NLast��PI�ľ��ȣ�,X(����)��
long double TaylarEPI(int N,long double X,long double LnPI,int NLast)
{
	long double Value=1;
	long double InterationsNum  =1;
	long double RoundimgError = 0,MethodError = 0,LastError=0,Error = 0;
	long double x = X*LnPI;
	long double xceil = ceil(x);
	long double mult=1;
	long double mult2 = 1;
	while (1)
	{
		RoundimgError = InterationsNum*0.5*pow(10,-18);
		LastError = LastError + pow(xceil,InterationsNum-1)/mult2;	
		LastError = LastError*X*0.5*pow(10,-NLast);
		MethodError = ceil(pow(3,xceil))*pow(xceil,InterationsNum)/mult;
		Error = RoundimgError + LastError + MethodError;
		if(InterationsNum>1)
		{
			mult2 = mult2*InterationsNum;
		}
		mult = mult *(InterationsNum+1);
		InterationsNum = InterationsNum +1;

		if(Error<0.5*pow(10,-N))
		{
			break;
		}
		
	}
	cout<<setiosflags(ios::fixed)<<setprecision(0)<<"The number of iterations : "<<InterationsNum;
	mult  =1;
	for(int ii=1;ii<=InterationsNum;ii++)
	{
		mult = mult*ii;
		Value = Value + pow(x,ii)/mult;
	}
	return Value;
}

//���������Ľ���ŷ��������PI^X
//������N�����ȣ���LnPI ����һ����õ�ֵ����NLast��PI�ľ��ȣ�,X(����)��
long double ImprovedEulerEPI(int N,long double X,long double LnPI,int NLast)
{
	long double Value=1;
	long double RoundimgError = 0,LastError=0,MethonError=0,Error=0;
	long double x = X*LnPI;
	long double xceil = ceil(x);
	long double h = x,n=1;
	while(1)
	{
		RoundimgError = pow(1+h+h*h/2,n)*(0.5*pow(10,-18)/(h))-0.5*pow(10,-18)/h;
		MethonError = pow(1+h+h*h/2,n)*(xceil*h*h/(3*(1+h/2)))-x*h*h/(3*(1+h/2));
		LastError = X*pow(2.8,xceil)*0.5*pow(10,-NLast);
		Error = RoundimgError+MethonError+LastError;
		if(Error<0.5*pow(10,-N))
		{
			break;
		}
		h = h/2;
		n = n*2;
	}
	h = h/2;
	n = n*2;
	cout<<setiosflags(ios::fixed)<<setprecision(0)<<"The number of iterations : "<<n;
	long double ypre;
	long double y0=1;
	for(int ii=0;ii<n;ii++)
	{
		ypre = y0 + h*y0;
		Value = y0 + h*(y0+ypre)/2;
		y0 = Value;
	}
	return Value;
}


//���ڷ����������������ʽ
long double SimpsonLnPiV2(int N,long double PI,int NLast,long double V)
{
	long double Value=0;
	long double InterationsNum  = 1;
	long double RoundimgError = 0,MethodError = 0,LastError=0,Error = 0;
	long double V5 = pow(V-1,5);

	while(1)
	{
		RoundimgError = 4*InterationsNum*0.5*pow(10,-18);
		LastError = 9*0.5*pow(10,-NLast);
		MethodError = 24*V5/(2880*pow(InterationsNum,4));
		long double Error = RoundimgError + LastError + MethodError;
		if(Error<0.5*pow(10,-N))
		{
			break;
		}
		InterationsNum = InterationsNum+1;
	}
	//cout<<setiosflags(ios::fixed)<<setprecision(0)<<"The number of iterations : "<<InterationsNum<<endl;
	long double h = (PI-1)/InterationsNum;
	Value = 1 + 1/PI + 4/(1+h/2);
	for(long double ii=1;ii<InterationsNum;ii++)
	{
		Value = Value + 2/(1+ii*h) + 4/(1+ii*h+h/2);
	}
	Value = Value*h/6;
	return Value;
}

///ţ�ٷ�
long double EquationRoot(int N,long double X,long double LnPI,long double PI,int NLast)
{
	long double Value=0,I=0;
	long double RoundimgError = 0,LastError=0,MethonError=0,InError = 0,Error=0;
	long double xlnPI = X*LnPI;
	long double xlnPIceil = ceil(xlnPI);//��ȡ��
	long double PIXFloor = floor(pow(PI,X));
	long double PIXCeil = ceil(pow(PI,X));
	long double M = 1/PIXFloor;
	int NIn = 12;//�������ι�ʽ����֪���
	int k=1;
	while(1)
	{
		RoundimgError = k*0.5*pow(10,-18);
		LastError = pow(2.8,xlnPIceil)*0.5*pow(10,-NLast);
		InError = k*PIXCeil*0.5*pow(10,-NIn);
		MethonError = pow(0.5*M,k);
		Error = RoundimgError+LastError+MethonError+InError;
		if(Error<0.5*pow(10,-N))
		{
			break;
		}
		k=k+1;
	}
	cout<<"The number of iterations : "<<k;
	Value = PIXCeil;
	for(int ii=0;ii<=k;ii++)
	{
		I = SimpsonLnPiV2(NIn,Value,15,Value);
		Value = Value*(1+xlnPI-I);
	}
	return Value;
}
void main()
{
	cout<<endl<<"##############  PI ############################"<<endl;
	long double PI,PI1,PIT;
	
	cout<<"����һ��̩��չ���� PI :"<<endl;
	int NPI1 = 6;
	PI1 = TaylarPi1(NPI1);
	cout<<endl<<setiosflags(ios::fixed)<<setprecision(NPI1)<<" PI = "<<PI1<<endl<<endl;
	
	cout<<"���������Ľ���̩��չ���� PI<������һ��> :"<<endl;
	int NLast1 = 15;
	PI = TaylarPi2(NLast1);
	cout<<endl<<setiosflags(ios::fixed)<<setprecision(NLast1)<<" PI = "<<PI<<endl<<endl;;

	cout<<"�����������ι�ʽ PI :"<<endl;
	int NPIT = 6;
	PIT = TrapezoidalPi(NPIT);
	cout<<endl<<setiosflags(ios::fixed)<<setprecision(NPIT)<<" PI = "<<PIT<<endl<<endl;
	
	cout<<endl<<"##############  Ln(PI) ############################"<<endl;
	long double LnPI,LnPI1,LnPI2;

	cout<<"����һ���Ľ���̩��չ���� Ln��PI����"<<endl;
	int NTaLn = 7;
	LnPI1 = TaylarLnPi(NTaLn,PI,NLast1);
	cout<<endl<<setiosflags(ios::fixed)<<setprecision(NTaLn-1)<<" Ln(PI) = "<<LnPI1<<endl<<endl;
	
	cout<<"�����������ι�ʽ�� Ln��PI����"<<endl;
	int NTILn = 6;
	LnPI2 = TrapezoidalLnPi(NTILn,PI,NLast1);
	cout<<endl<<setiosflags(ios::fixed)<<setprecision(NTILn)<<" Ln(PI) = "<<LnPI2<<endl<<endl;

	cout<<"����������������ʽ Ln��PI��<������һ��>��"<<endl;
	int NLast2 = 13;
	LnPI = SimpsonLnPi(NLast2,PI,NLast1);
	cout<<endl<<setiosflags(ios::fixed)<<setprecision(NLast2)<<" Ln(PI) = "<<LnPI<<endl<<endl;
	
	cout<<endl<<"##############  (PI)^X ############################"<<endl;
	long double X;
	long double TaPIX,ImEuPIX,NewtonPIX;

	cout<<"����һ�� ̩��չ���� PI^X��"<<endl;
	while(1)
	{   
		cout<<"������PI�Ĵη� X��1~10��:";
		cin>>X;
		if(X>10||X<1)
			cout<<"��������ֵ���ֵ����˴�����X��1~4��"<<endl;
		else
			break;
	}
	int NTaPIX = 6;
	TaPIX = TaylarEPI(NTaPIX,X,LnPI,NLast2);
	cout<<endl<<setiosflags(ios::fixed)<<setprecision(NTaPIX)<<" PI^"<<X<<" = "<<TaPIX<<endl<<endl;

	cout<<"�������� �Ľ���ŷ�������� PI^X��"<<endl;
	while(1)
	{   
		cout<<"������PI�Ĵη� X��1~10��:";
		cin>>X;
		if(X>10||X<1)
			cout<<"��������ֵ���ֵ����˴�����X��1~10��"<<endl;
		else
			break;
	}
	int NIm = 6;
	ImEuPIX = ImprovedEulerEPI(NIm,X,LnPI,NLast2);
	cout<<endl<<setiosflags(ios::fixed)<<setprecision(NIm)<<" PI^"<<X<<" = "<<ImEuPIX<<endl<<endl;

	cout<<"�������� ������������������������� �� PI^X��"<<endl;
	while(1)
	{   
		cout<<"������PI�Ĵη� X��1~4��:";
		cin>>X;
		if(X>4||X<1)
			cout<<"��������ֵ���ֵ����˴�����X��1~4��"<<endl;
		else
			break;
	}
	NIm = 6;
	NewtonPIX = EquationRoot(NIm,X,LnPI,PI,NLast2);
	cout<<endl<<setiosflags(ios::fixed)<<setprecision(NIm)<<" PI^"<<X<<" = "<<NewtonPIX<<endl<<endl;
	
	system("pause");
}