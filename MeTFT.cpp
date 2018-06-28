// 
// 
// 

#include "MeTFT.h"
MeTFTClass::MeTFTClass(void) :msTFT(0)
{
	//MeSerial ms(0);
	//msTFT = ms;
}
MeTFTClass::MeTFTClass(uint8_t port) : msTFT(port) 
{
	//MeSerial ms(port);
	//msTFT = ms;
	iPort = port; 
}
void MeTFTClass::init()
{
	//msTFT.begin(115200);
}
void MeTFTClass::begin(long speed)
{
	msTFT.begin(speed);
	
}
void MeTFTClass::AlterSpeed(long speed)
{
	String str;
	switch (speed)
	{
	case 9600:str = "U2"; break;
	case 19200:str = "U3"; break;
	case 38400:str = "U4"; break;
	case 57600:str = "U5"; break;
	case 115200:str = "U6"; break;
	case 256000:str = "U7"; break;
	default:str = "U6";
		break;
	}
	
	//msTFT.println(str);
	msTFT.println(str);
}
void MeTFTClass::tftPrint()
{
	String str;
	ClearScreenWithColor(ibackColor);
	delay(1000);
	str = str + "DS24"  + "(12,12," + "'print2 test'" + ",2)";
	msTFT.println(str);
	delay(1000);

}
void MeTFTClass::ClearScreenWithColor(uint16_t iColor)
{
	String str;
	ibackColor = iColor;
	str = "CLS(" + String(iColor) + ");";
	msTFT.println(str);	
}
void MeTFTClass::ShowPicture(uint16_t x,uint16_t y, uint16_t iPicNo)
{
	String str;
	str = "PIC(" + String(x) + "," + String(y) + "," + String(iPicNo) + ");";
	msTFT.println(str);

}
void MeTFTClass::ShowText(uint16_t x, uint16_t y, uint16_t iSize, uint16_t iColor,String Text )
{
	String str;
	str = "DS" + String(iSize) + "(" + String(x) + "," + String(y) + ",'" + Text + "'," + String(iColor) + ");";
	msTFT.println(str);

}
void MeTFTClass::ShowText(uint16_t x, uint16_t y, uint16_t iSize, uint16_t iColor, double dbNumber)
{
	String str;
	str = "DS" + String(iSize) + "(" + String(x) + "," + String(y) + ",'" + String(dbNumber)+ "'," + String(iColor) + ");";
	msTFT.println(str);

}
void MeTFTClass::ShowText(uint16_t x, uint16_t y, uint16_t iSize, uint16_t iColor, int iNumber)
{
	String str;
	str = "DS" + String(iSize) + "(" + String(x) + "," + String(y) + ",'" + String(iNumber) + "'," + String(iColor) + ");";
	msTFT.println(str);
}
void MeTFTClass::ShowDigit(uint16_t x, uint16_t y, uint16_t iSize, uint16_t iColor, double dbNumber, uint8_t iType)
{
	String str;	
	if (iType == 1)
	{
		str = "DS" + String(iSize) + "(" + String(x) + "," + String(y) + ",'" + String((int)dbNumber) + "'," + String(iColor) + ");" ; 
	}
	else
	{
		str = "DS" + String(iSize) + "(" + String(x) + "," + String(y) + ",'" + String(dbNumber) + "'," + String(iColor) + ");" ;
	}
	
	msTFT.println(str);
}
void MeTFTClass::DrawPoint(uint16_t x,uint16_t y,uint16_t iColor)
{
	String str;
	str = "PS(" + String(x) + "," + String(y) + "," + String(iColor) + ");";
	msTFT.println(str);
}
void MeTFTClass::DrawLine(uint16_t xBegin, uint16_t yBegin, uint16_t xEnd, uint16_t yEnd, uint16_t iColor)
{
	String str;
	str = "PL(" + String(xBegin) + "," + String(yBegin) + "," + String(xEnd) + "," + String(yEnd) + "," + String(iColor) + ");";
	msTFT.println(str);
}
void MeTFTClass::DrawRect(uint16_t xBegin, uint16_t yBegin, uint16_t xEnd, uint16_t yEnd, uint16_t iColor)
{
	String str;
	str = "BOX(" + String(xBegin) + "," + String(yBegin) + "," + String(xEnd) + "," + String(yEnd) + "," + String(iColor) + ");";
	msTFT.println(str);
}
void MeTFTClass::FillRect(uint16_t xBegin, uint16_t yBegin, uint16_t xEnd, uint16_t yEnd, uint16_t iColor)
{
	String str;
	str = "BOXF(" + String(xBegin) + "," + String(yBegin) + "," + String(xEnd) + "," + String(yEnd) + "," + String(iColor) + ");";
	msTFT.println(str);
}
void MeTFTClass::DrawCircleRect(uint16_t xBegin, uint16_t yBegin, uint16_t xEnd, uint16_t yEnd, uint16_t r, uint16_t iColor)
{
	String str;
	str = "CBOX(" + String(xBegin) + "," + String(yBegin) + "," + String(xEnd) + "," + String(yEnd) + "," + String(r) + "," + String(iColor) + ");";
	msTFT.println(str);
}
void MeTFTClass::FillCircleRect(uint16_t xBegin, uint16_t yBegin, uint16_t xEnd, uint16_t yEnd, uint16_t r, uint16_t iColor)
{
	String str;
	str = "CBOF(" + String(xBegin) + "," + String(yBegin) + "," + String(xEnd) + "," + String(yEnd) + "," + String(r) + "," + String(iColor) + ");";
	msTFT.println(str);
}
void MeTFTClass::DrawCircle(uint16_t xBegin, uint16_t yBegin, uint16_t r, uint16_t iColor)
{
	String str;
	str = "CIR(" + String(xBegin) + "," + String(yBegin) + ","+String(r)+"," + String(iColor) + ");";
	msTFT.println(str);

}
void MeTFTClass::FillCircle(uint16_t xBegin, uint16_t yBegin, uint16_t r, uint16_t iColor)
{
	String str;
	str = "CIRF(" + String(xBegin) + "," + String(yBegin) + "," +String(r)+","+ String(iColor) + ");";
	msTFT.println(str);

}
void MeTFTClass::SetTFTMode(uint8_t iMode)
{
	String str;
	str = "DR" + String(iMode);
	msTFT.println(str);
}
void MeTFTClass::TextBlink(uint16_t x, uint16_t y, uint16_t iSize, uint16_t iColor, String strText,uint16_t iTimes)
{
	String str;
	double CurrentTime, LastTime;
	for (int i = 0; i < iTimes; i++)
	{  
		ShowText(x,y,iSize,iColor,strText);
		delay(1000);
		ShowText(x, y, iSize, ibackColor, strText);
		delay(1000);
	}
}

MeTFTClass MeTFT;

