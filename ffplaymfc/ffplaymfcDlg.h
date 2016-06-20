/* 
 * FFplay for MFC
 *
 * ������ Lei Xiaohua
 * leixiaohua1020@126.com
 * �й���ý��ѧ/���ֵ��Ӽ���
 * Communication University of China / Digital TV Technology
 *
 * http://blog.csdn.net/leixiaohua1020
 * 
 * �����̽�ffmpeg��Ŀ�е�ffplay��������ffplay.c����ֲ����VC�Ļ����¡�
 * ����ʹ��MFC����һ�׼򵥵Ľ��档
 * This software transplant ffplay to Microsoft VC++ environment. 
 * And use MFC to build a simple Graphical User Interface. 
 */

#pragma once
#include "SysinfoDlg.h"
#include "afxwin.h"

// CffplaymfcDlg �Ի���
class CffplaymfcDlg : public CDialogEx
{
// ����
public:
	CffplaymfcDlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CffplaymfcDlg();

// �Ի�������
	enum { IDD = IDD_FFPLAYMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	CWinThread *pThreadPlay;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//Main Button
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedSeekB();
	afx_msg void OnBnClickedPause();
	afx_msg void OnBnClickedSeekF();
	afx_msg void OnBnClickedStop();
	afx_msg void OnBnClickedSeekStep();
	afx_msg void OnBnClickedFullscreen();
	afx_msg void OnBnClickedInputurlButton();
	
	//Control
	CEdit m_currentclock;
	CEdit m_duration;
	CSliderCtrl m_playprogress;
	CEdit m_inputurl;

	CString _strBitrate;
	CString _strDuration;
	CString _strInputFormat;
	CString _strMetaData;
	CString _strProtocol;
	CString _strCodecAChannels;
	CString _strCodecAName;
	CString _strCodecASampleRate;
	CString _strCodecVFramerate;
	CString _strCodecVPixfmt;
	CString _strCodecVName;
	CString _strCodecVResolution;

	void ResetBtn();
	void ActiveBtn();
	
	//Dialog
	void SystemClear();
	SysinfoDlg *sidlg;
	void CreateSubWindow();
	void FreeSubWindow();

	afx_msg void OnDropFiles(HDROP hDropInfo);
	//Menu
	afx_msg void OnAbout();
	afx_msg void OnSysinfo();
	afx_msg void OnSeekF60();
	afx_msg void OnSeekB60();
	afx_msg void OnSeekF600();
	afx_msg void OnSeekB600();
	afx_msg void OnWindowYuv();
	afx_msg void OnWindowWave();
	afx_msg void OnWindowRdft();
	afx_msg void OnSize50();
	afx_msg void OnSize75();
	afx_msg void OnSize100();
	afx_msg void OnSize125();
	afx_msg void OnSize150();
	afx_msg void OnSize200();
	afx_msg void OnSize400();
	afx_msg void OnAspect11();
	afx_msg void OnAspect43();
	afx_msg void OnAspect169();
	afx_msg void OnAspect1610();
	afx_msg void OnAspect235100();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnWebsite();
	afx_msg void OnIdcancel();


	afx_msg void OnWindowstretchKeepratio();
	afx_msg void OnWindowstretchResize();
	CStatic _displayWnd;
};
