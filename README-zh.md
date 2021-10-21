# 介绍

- 图片大小、文字大小不合适你都可以调，cls代码简洁明了。
- 想添加内容也很简单，比如在封面添加「指导教师」这一项，你看看其他选项如何声明并传参的就可以了。

更多样式请点击这里：https://muyuuuu.github.io/2020/10/20/XDU-report-LaTeX-template/

# 文档目录与编译方式

`windows` 和 `Arch Linux` 都跑通了，`TexLive 2020`，编译方式为 `xelatex` 配 `bibtex`。

```bash
Shu-latex
├─ chapter                                  # 各个章节
│    ├─ abstract.tex                            # 摘要页
│    ├─ appendix.tex                            # 附录
│    ├─ conclusion.tex                          # 实验结果分析
│    ├─ experiment.tex                          # 实验步骤
│    └─ reference.tex                           # 参考文献
├─ figure                                   # 图片文件
│    ├─ 1.jpg                                   # logo
│    └─ 4.jpg                                   
├─ code                                     # 代码文件
│    └─ demo.c                                  # 一个C语言样例代码
├─ books.bib                                # 参考文献的 bib 文件
├─ main.bbl                                 # 编译生成的 bbl 文件，不用管
├─ main.pdf                                 # 结果 pdf 文件
├─ main.tex                                 # 要编译的主文件
└─ shureport.cls                            # 要导入的文档类
```


# 其他

- 代码字体为 `IBM Plex Mono`，没有的话换一个或下载安装；
