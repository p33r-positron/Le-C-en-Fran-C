# 0-Préparation

## Un peu d'histoire et des raisons d'apprendre le C

Le C est un langage crée dans les années 70 par Dennis Ritchie et Kenneth Thompson.
C'est un des langages de programmations qui a rendu la programmation accessible à tous !
Parce-que un bout de code en C qui affiche "Coucou !" à l'écran, on prend sa source...
...Et on peut la faire marcher sur tous les ordinateurs (Du moins si ils ont les logiciels pour).
Donc le C était génial car il était disponible sur tout ordinateur et tout système d'exploitation !
Aujourd'hui le C est peu à peu oublié, alors que presque tous les logiciels qui font vivre
les langages de programmation de maintenant sont fait (directement ou indirectement) grâce à lui !
Ces jeunes d'aujourd'hui avec leur python !
Mais je digresse, aujourd'hui le C à la particularité d'être extrêment rapide ! (Par rapport à python, ruby et compagnie)
Donc le C est un bon choix comme premier langage, surtout que la majorité des langages de programmations modernes
utilisent la syntaxe du C ("C-like syntax", en anglais), je peux citer C++, Java, PHP, JavaScript et d'autres...
De plus, tous ce que vous apprenez en C peut être utilisé en C++, si vous souhaitez l'apprendre pour faire des jeux, par exemple...
Le C est considéré comme "Bas niveau", cela veut dire qu'il est plus compréhensible par l'ordinateur que par nous...
...Mais bon, je vous rassure, on ne va pas taper des zéros et des uns pour autant !
En contre-exemple on peut citer le python (Oui je vais m'acharner dessus) qui est très compréhisemble pour nous...
...Par-contre pour la machine, elle doit prendre du temps à tout transformer...
Bref, dernière chose, sachez qu'en apprenant le C vous comprendrez mieux comment votre ordinateur fonctionne !
La mémoire ("RAM") en particulier !

## Compilateur ? N'ayez point peur !

Le Compilateur est un gentil programme qui se charge de convertir votre mignon code en C...
...en un programme fait de zéros et de uns que votre ordinateur se fera une joie de lancer !
Si il le faut, il le convertira d'abord dans des langages très compliqués (Comme le "langage assembleur") puis en binaire.
Il vous criera dessus quand vous ferez de trop grossières erreurs, mais ça va aller, il en a vu d'autres...

Donc première chose à faire, télécharger un compilateur ! (À moins que vous préfériez faire le votre, dans ce cas là vous êtes fou)
Je suis sous GNU/Linux mais je vais vous donner les étapes pour tous les systèmes !

### Micro$oft Windows

Sous Micro$oft Windows, je vous recommande TCC (Même si MinGW est techniquement mieux).
Sa particularité est d'être très petit et de faire des programmes très petits !
Vous pouvez le télécharger pour [32 BITS](http://download.savannah.gnu.org/releases/tinycc/tcc-0.9.27-win32-bin.zip) ou [64-BITS](http://download.savannah.gnu.org/releases/tinycc/tcc-0.9.27-win64-bin.zip).
Ensuite il faudra extraire le petit .zip à l'aide d'un clic droit, et puis l'ajouter au path...
Je vous laisse chercher sur internet, ça serait trop long à expliquer... (Désolé)

### Mac OS X / Mac OS XI

Normalement GCC ou clang devrait être installé de base.
Pour vérifier ça, ouvrez un terminal et tapez "gcc" (Sans guillemets)
Si cela vous met un texte "No input file" ou "Aucun fichier d'entrée" alors tout va bien
Sinon essayez de taper "clang" (Sans guillemets) 
Si pareil il n'y a pas de texte "No input file" ou "Aucun fichier d'entrée"...
...Installez XCode depuis le DVD d'installation de Mac OS X ou l'App Store sur les plus récents.

### GNU/Linux et BSD

GCC est fourni de base, si vous utilisez Alpine Linux, entrez la commande "apk add build-base" (Sans guillemets) dans un Terminal.

## Dernières choses

Il vous faut un éditeur de texte, le bloc-note integré à votre système (Notepad, TextEdit, Leafpad, Mousepad...) suffira.
Mais je vous conseille d'installer un bon éditeur de texte tel que Notepad++ sous Windows ou Sublime Text (Tout système)

## Fin

Ce tutoriel était un peu court, oui, mais il demandait juste les préparations nécéssaire pour pouvoir programmer en C.
Dans les prochains chapitres nous allons voir des nécéssités requises pour comprendre le langage C,
car beaucoup de tutoriels vous donne un code qui marque "Hello, World !" à l'écran,
mais n'expliquent le fonctionnement qu'après, c'est pas très bien je trouve.
