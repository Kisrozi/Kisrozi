// MeTFT.h

#ifndef _METFT_h
#define _METFT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <MeSerial.h>
#include <MeConfig.h>
class MeTFTClass
{
 protected:
	 MeSerial msTFT;
	 uint16_t ibackColor;//��������ɫ
	 uint8_t iPort;


 public:
	 MeTFTClass(void);
	 MeTFTClass(uint8_t port);
	void init();
	void tftPrint();
	void begin(long speed);//����Ƶ��
	void AlterSpeed(long speed);
	void ClearScreenWithColor(uint16_t iColor);//����ɫiColor����
	void ShowPicture(uint16_t x,uint16_t y, uint16_t iPicNo);//��ʾͼƬ
	
	void ShowText(uint16_t x, uint16_t y, uint16_t iSize, uint16_t iColor,String Text );//��ָ��λ����ʾ�ַ�	
	void ShowText(uint16_t x, uint16_t y, uint16_t iSize, uint16_t iColor, double dbNumber);//ָ��λ����ʾ������
	void ShowText(uint16_t x, uint16_t y, uint16_t iSize, uint16_t iColor, int iNumber);//ָ��λ����ʾ����
	void ShowDigit(uint16_t x, uint16_t y, uint16_t iSize, uint16_t iColor, double dbNumber,uint8_t iType);

	void DrawPoint(uint16_t x,uint16_t y,uint16_t iColor);
	void DrawLine(uint16_t xBegin, uint16_t yBegin, uint16_t xEnd, uint16_t yEnd, uint16_t iColor);
	void DrawRect(uint16_t xBegin, uint16_t yBegin, uint16_t xEnd, uint16_t yEnd, uint16_t iColor);
	void FillRect(uint16_t xBegin, uint16_t yBegin, uint16_t xEnd, uint16_t yEnd, uint16_t iColor);	
	void DrawCircleRect(uint16_t xBegin, uint16_t yBegin, uint16_t xEnd, uint16_t yEnd, uint16_t r, uint16_t iColor);
	void FillCircleRect(uint16_t xBegin, uint16_t yBegin, uint16_t xEnd, uint16_t yEnd, uint16_t r, uint16_t iColor);
	void DrawCircle(uint16_t xBegin, uint16_t yBegin, uint16_t r, uint16_t iColor);
	void FillCircle(uint16_t xBegin, uint16_t yBegin, uint16_t r, uint16_t iColor);
	void SetTFTMode(uint8_t iMode);
	void TextBlink(uint16_t x, uint16_t y, uint16_t iSize, uint16_t iColor, String strText,uint16_t iTimes);
};

extern MeTFTClass MeTFT;

#endif

