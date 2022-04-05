\ProvidesClass{shureport}
\LoadClass[a4paper,12pt]{ctexart}
\RequirePackage{graphicx}
\RequirePackage{geometry}
\RequirePackage{fontspec}
\RequirePackage{fancyhdr}
\RequirePackage{lipsum}
\RequirePackage{zhlipsum}
\RequirePackage{xcolor}
\usepackage{titlesec}
\usepackage{geometry}
\usepackage{amsmath}
\usepackage{amssymb}
%\usepackage{extarrows}
%\usepackage{diagbox}
\usepackage{fancyhdr}
\usepackage{listings}
\usepackage{xcolor}
%\usepackage{tabularx}
\usepackage{graphicx}
\usepackage{caption}
% 代码高亮方案宏包
\RequirePackage{listings}
% \setmainfont{texgyrepagella-regular.otf} 
\setmainfont{Times New Roman}
% 设置等宽的代码字体
% \setmonofont{Courier New}
\setmonofont{IBM Plex Mono}
% \setmonofont{Source Code Pro}
\bibliographystyle{IEEEtran}
% 处理url连接
\usepackage{hyperref}
\makeatletter
\def\UrlAlphabet{%
      \do\a\do\b\do\c\do\d\do\e\do\f\do\g\do\h\do\i\do\j%
      \do\k\do\l\do\m\do\n\do\o\do\p\do\q\do\r\do\s\do\t%
      \do\u\do\v\do\w\do\x\do\y\do\z\do\A\do\B\do\C\do\D%
      \do\E\do\F\do\G\do\H\do\I\do\J\do\K\do\L\do\M\do\N%
      \do\O\do\P\do\Q\do\R\do\S\do\T\do\U\do\V\do\W\do\X%
      \do\Y\do\Z}
\def\UrlDigits{\do\1\do\2\do\3\do\4\do\5\do\6\do\7\do\8\do\9\do\0}
\g@addto@macro{\UrlBreaks}{\UrlOrds}
\g@addto@macro{\UrlBreaks}{\UrlAlphabet}
\g@addto@macro{\UrlBreaks}{\UrlDigits}

\geometry{top=1.25in,bottom=1.25in,left=1.25in,right=1.25in}

\titleformat*{\section}{\Large\bfseries}

% 信息
\newcommand\major[1]{\def\@major{#1}}
\newcommand\name[1]{\def\@name{#1}}
\newcommand\stuid[1]{\def\@stuid{#1}}
\renewcommand\date[1]{\def\@date{#1}}
\newcommand\expname[1]{\def\@expname{#1}}
\newcommand\course[1]{\def\@course{#1}}

%页眉页脚
\pagestyle{fancy}
\fancyhead[L]{\@name}
\fancyhead[C]{\@expname}
\fancyhead[R]{\@stuid}

% 封面
\newcommand{\makecover}{
  \thispagestyle{empty}
  \newgeometry{top=1.5in}
  \begin{center}
    \begin{center}
      \includegraphics[width=10cm]{figure/cover.png}
    \end{center}
    \vspace{1cm}
    \bfseries\huge{\@course}\\
    \vspace{0.5cm}
    \bfseries\Large{\@expname}
    \vspace{2cm}
    \begin{center}
      \large
      \renewcommand\arraystretch{1.6}
      \begin{tabular}{p{2cm}p{6cm}}
        \bfseries{姓名：} & \@name   \\ \cline{2-2}
        \bfseries{学号：} & \@stuid  \\ \cline{2-2}
        \bfseries{专业：} & \@major  \\ \cline{2-2}
      \end{tabular}
    \end{center}
    \vfill
    \Large{\@date}
  \end{center}
  \newpage
  \newgeometry{top=1.25in,bottom=1.25in,left=1.25in,right=1.25in}
}

% 环境
\newenvironment{note}{\kaishu 注：}{}
\newenvironment{code}{\linespread{0.85}}{}

% 代码高亮
\definecolor{CPPLight}  {HTML} {686868}
\definecolor{CPPSteel}  {HTML} {888888}
\definecolor{CPPDark}   {HTML} {262626}
\definecolor{CPPBlue}   {HTML} {4172A3}
\definecolor{CPPGreen}  {HTML} {487818}
\definecolor{CPPBrown}  {HTML} {A07040}
\definecolor{CPPRed}    {HTML} {AD4D3A}
\definecolor{CPPViolet} {HTML} {7040A0}
\definecolor{CPPGray}  {HTML} {B8B8B8}
\lstset{
  basicstyle=\scriptsize\ttfamily,
  % numbers=left,
  numberstyle=\scriptsize\ttfamily,
	breaklines=true,
	columns=fixed,       
	frame=bt,                                          % 四条边框
	backgroundcolor=\color[RGB]{250,250,250},            % 设定背景颜色
	keywordstyle=\color[RGB]{40,40,255},                 % 设定关键字颜色
	commentstyle=\itshape\color[RGB]{0,96,96},                % 设置代码注释的格式
	stringstyle=\slshape\color[RGB]{128,0,0},   % 设置字符串格式
	showstringspaces=false,                              % 不显示字符串中的空格
	morekeywords={alignas,continute,friend,register,true,alignof,decltype,goto,
		reinterpret_cast,try,asm,defult,if,return,typedef,auto,delete,inline,short,
		typeid,bool,do,int,signed,typename,break,double,long,sizeof,union,case,
		dynamic_cast,mutable,static,unsigned,catch,else,namespace,static_assert,using,
		char,enum,new,static_cast,virtual,char16_t,char32_t,explict,noexcept,struct,
		void,export,nullptr,switch,volatile,class,extern,operator,template,wchar_t,
		const,false,private,this,while,constexpr,float,protected,thread_local,
		const_cast,for,public,throw,std},
	emph={map,set,multimap,multiset,unordered_map,unordered_set,numpy,graph,path,append,extend,
		unordered_multiset,unordered_multimap,vector,string,list,deque,
		array,stack,forwared_list,iostream,memory,shared_ptr,unique_ptr,
		random,bitset,ostream,istream,cout,cin,endl,move,default_random_engine,
		uniform_int_distribution,iterator,algorithm,functional,bing,numeric,},
	emphstyle=\color{CPPViolet}, 
}
