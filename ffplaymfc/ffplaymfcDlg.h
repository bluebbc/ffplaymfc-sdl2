﻿/* 
 * FFplay for MFC
 *
 * 雷霄骅 Lei Xiaohua
 * leixiaohua1020@126.com
 * 中国传媒大学/数字电视技术
 * Communication University of China / Digital TV Technology
 *
 * http://blog.csdn.net/leixiaohua1020
 * 
 * 本工程将ffmpeg项目中的ffplay播放器（ffplay.c）移植到了VC的环境下。
 * 并且使用MFC做了一套简单的界面。
 * This software transplant ffplay to Microsoft VC++ environment. 
 * And use MFC to build a simple Graphical User Interface. 
 */

#pragma once
#include "flvmaker.h"
#include "SysinfoDlg.h"
#include "afxwin.h"

// CffplaymfcDlg 对话框
class CffplaymfcDlg : public CDialogEx
{
// 构造
public:
	CffplaymfcDlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~CffplaymfcDlg();

// 对话框数据
	enum { IDD = IDD_FFPLAYMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	CWinThread *pThreadPlay;

	// 生成的消息映射函数
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

	// 文件
	CFlvMaker *_pFlvMaker;

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
