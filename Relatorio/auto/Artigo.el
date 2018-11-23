(TeX-add-style-hook
 "Artigo"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "12pt")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8") ("babel" "brazil")))
   (TeX-run-style-hooks
    "latex2e"
    "Introducao"
    "Metodologia"
    "Resultados"
    "article"
    "art12"
    "sbc-template"
    "graphicx"
    "url"
    "inputenc"
    "babel"
    "minted")
   (LaTeX-add-bibliographies
    "referencias"))
 :latex)

