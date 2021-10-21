[简体中文](https://github.com/muyuuuu/XDU-report-LaTeX-template/blob/main/README-zh.md)|[English](https://github.com/muyuuuu/XDU-report-LaTeX-template/blob/main/README.md)

# Intro


The template's target is simple, applicable and easy to expand, so:

- In `.cls` file, the figure size and font family can be modified easily.
- You can imitate how the current items are added if you want add other items such as supervisor.


# Files structure and compilation method

This code has run in `windows10` and `Arch` successfully, platform is `texlive2020` and compilation is `xelatex +bibtex`.

```
SHU-latex
├─ chapter                                  # The chapters
│    ├─ abstract.tex                            # The abstract
│    ├─ appendix.tex                            # The appendix
│    ├─ conclusion.tex                          # The conclution of experiment
│    ├─ experiment.tex                          # How to set experiment
│    └─ reference.tex                           # The references
├─ figure                                   # The figures
│    ├─ 1.jpg                                   # SHU logo
│    └─ 4.jpg                                   # SHU text
├─ code                                     # The Code files
│    └─ demo.c                                  # A C language demo
├─ books.bib                                # The bib file of reference
├─ main.bbl                                 # The record file of reference
├─ main.pdf                                 # The only file you should submit
├─ main.tex                                 # The main file should be compiled
└─ shureport.cls                            # The document class
```

# Others

- The font of code is `IBM Plex Mono`, you can download and install it, or replace it with other fixed width font.