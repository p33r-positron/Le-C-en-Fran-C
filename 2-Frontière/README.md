# Préambule

Bienvenue sur ce chapitre Nº2 du C en Fran-C !  
On va parler des entrées/sorties (D'où le nom "frontière")  
Et nous allons enfin afficher du texte !  
...Mais avant ça il va falloir parler de notre ami le compilateur !  

# Erreurs de Compilation

Il va (très (très (très (recursion)))) souvent arriver que votre code ne marche pas du premier coup.  
Il faut veiller aux erreurs de compilation qui pourront vous indiquer des erreurs bêtes (Confondre = et ==) ou invisibles.  
Le compilateur a beaucoup de patience, comme dit plus tôt, il en a vu d'autres :P  
  
Bref, voilà le petit guide pour résoudre les erreurs de compilation:  
1) Vérifier son code, en particulier les lignes indiqués par le compilateur, histoire de résoudre des `;` et `}` manquants  
2) Si vous parlez anglais (Vous le devriez, c'est utile :P) essayez de voir l'erreur, ou au pire, traduisez en ligne  
3) Cherchez sur google en collant une partie de l'erreur, 99,99% de chance de trouver un lien sur le Saint-Forum, stackoverflow.com 

Et pour les erreurs d'exécution, c'est soit le débogueur (On verra plus tard), soit mettre des printf\* partout.  
\*printf: Vous allez bientôt voir :P  

C'est tout pour les erreurs de compilation, mais retenez-le, ça va vous servir ! :)  

# Entrée/Sortie Basique

Pour afficher du texte à l'écran, on a le choix:  
-Utiliser une bibliothèque déjà écrite (Simple et courant)  
-Utiliser les syscalls (Moyen)  
-Utiliser l'assembleur (Dur)  
-Déréférencer les addresses mémoires de la carte vidéo/du VGA pour afficher des caractères à l'écran (Très dur)  
Pour des raisons de simplicité, on va utiliser seulement les deux premières manières, pour la dernière c'est plus pour l'OSDEV  

## Pratique

### Un gentil caractère

Ce qu'il faut comprendre c'est qu'on écrit caractère par caractère.  
Si je vous dis ça c'est pour que vous compreniez un truc:  
Vous vous souvenez quand je vous ai appris à déclarer un string avec la manière array ?  
Rappel:  
```c
char nom[4] = {'L', 'e', 'o', '\0'};
```  
On rajoutait toujours ce fameux `'\0'`, qui signifie l'élément Nº0 de la table ASCII, c'est à dire le null terminator  
Vous allez bientôt comprendre son utilité ;)  
  
Pour commencer, on va utiliser la bibliothèque io/unistd, qui permet de faire des entrées sorties de bas niveau  
\[CORRECTION\]: Sous Micro$oft Windows c'est io.h, sous tous les autres systèmes (Enfin la norme POSIX / Type UNIX) c'est unistd.h (normalement)  
La bonne chose à faire serait:  
```c
#if defined(WIN32) || defined(_WIN32) //Si on détecte Windows
#include <io.h> //Alors io.h
#else //Sinon
#include <unistd.h> //Alors unistd.h
#endif //Fin
```  
Dans votre main.c, mettez:  
```c
//Faîtes votre choix, ou copiez-collez le petit code ci-dessus à la place
//#include <io.h> //Décommentez pour Windows, commentez pour POSIX/Type UNIX
#include <unistd.h> //Décommentez pour POSIX/Type UNIX, commentez pour Windows

int main(void)
{
  //Coucou !
  return 0;
}
```  
Maintenant, on va afficher un caractère tout seul pour commencer:  
```c
//Pour la suite du cours je laisse unistd.h, si vous voulez tester sous Windows n'oubliez pas
//de remplacer par io.h ou par le code en haut afec les #if / #else / #endif
#include <unistd.h>

int main(void) //Pas besoin d'arguments
{
  char lettreAmaj = 'A';
  write(1, &lettreAmaj, sizeof(char)); //On peut remplacer sizeof(char) par 1 ;)
  return 0;
}
```  

Explications:
La variable lettreAmaj contient `'A'` (Ou 65 en ASCII)  
La fonction write prends 3 arguments: Où écrire (Le flux), un pointeur vers la valeur à écrire, la taille en octets de cette valeur  
Ici, on a écrit vers... 1 ? Qui correpond à stdout -> standard output -> sortie standard (En anglais), universellement  
Bref, si on compile et exécute tout ça, on devrait voir le caractère `A` !  
\**Attention aux utilisateurs de systèmes types UNIX (Mac OS X/GNU+Linux/\*BSD), pas de retour automatique à la ligne, le A risque d'être à gauche de la prochaine ligne*  
  
### Une chaîne de caractère/String

Pareil, mais avec une boucle !  
```c
#include <unistd.h>

int main(void)
{
  char nom[5] = {'L', 'e', 'o', '!', '\0'};
  int i = 0;
  while(nom[i] != 0)
  {
    write(1, &nom[i++], sizeof(char)); //On utilise i++ pour ne pas incrémenter juste après
  }
  return 0;
}
```  
Les petits malins savent qu'avec un char* on peut utiliser le tableau comme un pointeur et faire plus simple:  
```c
#include <unistd.h>

int main(void)
{
  char* nom = "Tom!";
  while(nom != 0)
  {
    write(1, nom++, sizeof(char)); //nom est déjà un pointeur, pas besoin de faire &nom++
    //nom++ incrémente déjà
  }
  return 0;
}
```  
Bref, maintenant que vous savez tout ça, on va passer à stdio !  

# Texte avec stdio

Une bibliothèque qui vous servira toute votre vie :D  
stdio -> standard input/ouput -> entrée/sortie standard  
Ça va vous faciliter la vie, maintenant que vous avez compris le write(), laissez tomber !  
Faîtes juste `putchar('A');` !  
Bref.  
C'est une bibliothèque qui contient plein de fonctions très utiles, dont la première qu'on va utiliser:  
![](assets/puts.png)  
Exemple d'utilisation:  
```c
#include <stdio.h> //Ne pas oublier la sainte-bibliothèque

int main(void)
{
  char* message = "Vous allez bien ?";
  puts("Coucou tout le monde !");
  puts(message);
  return 0;
}
```  

## Affichages Formattés

Comment passer à-coté de **printf** ?  
printf -> print formatted -> imprimer formatté/avec format  
Vous allez comprendre avec un petit exemple:  
```c
#include <stdio.h>

int main(void)
{
  int a = 349;
  printf("a vaut %d\n", a);
  return 0;
}
```  
\*Pour information: `\n` compte pour un seul caractère: un retour à la ligne.  
Bref, ce programme affichera `a vaut 349` et un retour à la ligne  
C'est super n'est-ce pas ?  
Voilà une petite description de printf:  
![](assets/printf.png)  
Ainsi qu'une aide pour le formattage du texte:  
![](assets/format.png)  
Elle n'est pas complète, on peut aussi citer `%u` pour les nombres unsigned/sans signes/positifs par exemple...  

## Et le clavier ?

Oui, enfin, l'utilisateur va nous parler !  
Dans entrée/sortie, on a vu la sortie, maintenant l'entrée !  
Grâce à `scanf` !  
Et oui, on retrouve encore ce fameux f, ce qui veux dire formata-  

### Un nombre ça serait pas mal

```c
#include <stdio.h>

int main(void)
{
  int age = 0; //Variable utile
  printf("Entrez votre age s'il vous plait: "); //printf pour éviter le retour à la ligne ;)
  scanf("%u", &age); //u -> nombre non signé, évitons l'âge négatif :P
  //On utilise l'adresse mémoire de age et non age, pour qu'il puisse être modifié ;) | Non nécéssaire pour les char*
  //L'utilisateur, en appuyant sur entrée, à déjà fait un retour à la ligne :P
  printf("Vous avez %u ans !\n", age);
  return 0;
}
```  
Vous devriez comprendre en lisant mes commentaires :)  
Bref, on peut demander un char (`%c`), un string/char\* (`%s`), un nombre à virgule float (`%f`), etc...  

### Juste un chiffre !

On va utiliser une propriétée interessante de scanf: la possibilité de limiter la taille de ce que l'utilisateur entre !  
```c
#include <stdio.h>

int main(void)
{
  int chiffre = 2;
  do
  {
    printf("Entrez un chiffre entre 1 et 9 inclus: ");
    scanf("%1d", &chiffre); //Si l'utilisateur entre 349 (Par ex.), chiffre vaudra 3 !
  }while(chiffre < 1 || chiffre > 9); //Si l'utilisateur ne rentre rien, chiffre vaudra 0
  
  printf("%d est la racine carré de %d !\n", chiffre, chiffre*chiffre); //chiffre est la racine carré de chiffre*chiffre
  return 0;
}
```  

### Un string ?

La solution bête serait:  
```c
#include <stdio.h>

int main(void)
{
  char prenom[32];
  printf("Entrez votre prenom: ");
  scanf("%s", prenom); //Un tableau est un pointeur :P
  printf("Bonjour, %s\n", prenom);
  return 0;
}
```  
Pauvre fou ! Vous voulez vraiment avoir un...
...***Buffer Overflow*** ? *Musique Dramatique*  
(Buffer Overflow -> Dépassement de Tampon)  
Pour faire simple, quelqu'un pourrait mettre plus de 32 caractères, et faire planter le programme !  
Ou pire, exécuter du code arbitraire, et, qui sait, élever ses privilèges !  
Bref, voilà la bonne manière:  
```c
#include <stdio.h>

int main(void)
{
  char prenom[32];
  printf("Entrez votre prenom: ");
  scanf("%31s", prenom); //Tableau->Pointeur | 1 de plus, 1 de moins (Au cas où pour le Null Terminator)
  printf("Bonjour, %s\n", prenom);
  return 0;
}
```  

### Tout mélanger

```c
#include <stdio.h>

int main(void)
{
  char lettreCase = 'Z';
  int nombreCase = 0;
  int retour = 0;
  puts("Bienvenue sur plateau d'echec simulator 2021 !");
  do
  {
    printf("Entrez une case: ");
    retour = scanf("%c%d", &lettreCase, &nombreCase); //scanf renvoie le nombre de valeurs entrées, ici on en attend deux !
  } while(retour != 2 || lettreCase < 'A' || lettreCase > 'H' || nombreCase < 1 || nombreCase > 8);
  printf("Je teleporte mon roi et son katana laser en %c%d, echec et mat !\n", lettreCase, nombreCase);
  return 0;
}
```  
Et voilà une petite description de la fonction:  
![](assets/scanf.png)  

# Lecture et écriture sur le disque avec stdio

Cette fois on va éviter de faire en bare metal avec IO.h même si c'est possible :)  
On va utiliser toutes les commandes qui commencent par f (fopen, fwrite, fprintf, fscanf, fgetc, fgets, fclose...)  

## Ouvrir un fichier

C'est plus dur que ça en à l'air: Il faut faire un choix  
Lire ? (Ré)Écrire ? Rajouter ? Fichier normal ou Binaire ? Plusieurs modes ?  
Alors on va faire les bases:  
r -> read -> lire  
w -> write -> écrire  
a -> append -> rajouter  
b -> binary -> binaire  
\+ -> plus ?  
  
Si on ouvre le fichier en mode r, on peut seulement le lire.  
Si on ouvre le fichier en mode w, il sera vidé si il existe, et on peut seulement écrire.  
Si on ouvre le fichier en mode a, il sera crée si il n'existe pas, et on peut seulement écrire depuis la "fin".  
Si on ouvre le fichier en mode r+, on peut lire et écrire.  
Si on ouvre le fichier en mode w+, il sera vidé si il existe, et on peut lire et écrire.  
Si on ouvre le fichier en mode a+, il sera crée si il n'existe pas, on peut lire le fichier mais l'écriture n'est que depuis la "fin".  
Si on ouvre le fichier en mode rb, on lit des octets (des bits par 8, du binaire en gros) et pas du texte.  
Si on ouvre le fichier en mode wb, il sera vidé si il existe, et on écrit des octets (des bits par 8, du binaire en gros) et pas du texte.  
Si on ouvre le fichier en mode ab, il sera crée si il n'existe pas, et on écrit des octets (des bits par 8, du binaire en gros) et pas du texte, depuis la "fin".  
Si on ouvre le fichier en mode rb+, c'est comme r+ mais version binaire/rb (flemme).  
Si on ouvre le fichier en mode wb+, c'est comme w+ mais version binaire/wb (flemme).  
Si on ouvre le fichier en mode ab+, c'est comme a+ mais version binaire/ab (flemme).  
  
Ça à l'air un peu compliqué, donc j'ai pris la liberté de traduire un arbre de décision trouvé sur stackoverflow.com:  
![](assets/rwa.png)  
Créateur Original: Andrzej Pronobis  
  
### Pratique

```c
#include <stdio.h>

int main(void)
{
  FILE* fichier = 0; //On met la valeur de fichier à 0
  fichier = fopen("./test.txt", "a"); //Si le fichier n'arrive pas à s'ouvrir, fichier aura comme valeur NULL/0, donc il n'aura pas changé de valeur
  if(fichier == 0) //Si il n'a pas changé de valeur, c'est qu'il y a une erreur
  {
    puts("Erreur pendant l'ouverture du fichier :(");
    return 1;
  }
  else //Sinon on essaye d'écrire dans le fichier
  {
    int writeTest = fputs("Bonjour !\n", fichier); //fputs, lui, n'ajoute pas de nouvelle ligne automatiquement :(
    if(writeTest < 0) //puts et fputs retournent une valeur >= 0 si tout va bien
    {
      puts("Erreur pendant l'écriture dans le fichier :(");
      return 1;
    }
    else
    {
      puts("Regardez le contenu de test.txt :)");
      writeTest = fclose(fichier); //Fermer le fichier
      if(writeTest != 0)
        puts("Erreur pendant la fermeture du fichier :(");
      return 0;
    }
  }
}
```  
Pensez à regarder mes commentaires :)  
![](assets/fopen.png)  
![](assets/fputs.png)  
![](assets/fclose.png)  

#### FILE* ?

On le verra plus tard, il existe **struct**: Un mot magique qui permet d'aller plus proche vers la programmation objet :)  
Bref, stdio.h à crée le type FILE* (Ou plutôt FILE, FILE* est un pointeur) qui permet d'identifier un fichier.  

#### ./test.txt

./test.txt = Le fichier test.txt **dans le dossier d'exécution**  
Avec certaines commandes il est possible d'utiliser le dossier ou se trouve le programme, je vous expliquerai la différence plus tard :)  
Bref, ./test.txt c'est test.txt, et c'est aussi .\\test.txt, ainsi que /<DossierActuel>/test.txt ou C:\\<DossierActuel>\\test.txt  

### Encore de la pratique

```c
#include <stdio.h>

void cesar(char* caractere) //Utilisons les pointeurs !
{
  if((*caractere < 'A' || *caractere > 'Z') && (*caractere < 'a' || *caractere > 'z')) //Si ce n'est pas une lettre latine, fin!
    return; //Une fonction s'arrête après un return
  switch(*caractere) //Parce-que en césar après Z il y a A, ce n'est pas le cas en ASCII.
  {
    case 'X':
      *caractere = 'A';
      break;
    case 'Y':
      *caractere = 'B';
      break;
    case 'Z':
      *caractere = 'C';
    case 'x':
      *caractere = 'a';
      break;
    case 'y':
      *caractere = 'b';
      break;
    case 'z':
      *caractere = 'c';
    default:
      *caractere = (*caractere) + 3; //On rajoute 3, on chiffre en césar !
  }
}

int main(int argc, char** argv)
{
  if(argc != 2) //Vérification de si il y a exactement deux arguments (En comptant le programme, donc un seul vrai argument)
  {
    puts("Utilisation: cesar <fichier>"); //Message d'erreur
    return 1;
  }

  //Ouverture du fichier en lecture
  FILE* fichier = NULL;
  fichier = fopen(argv[1], "r");
  if(fichier == NULL) //En cas d'échec d'ouverture
  {
    puts("Erreur pendant l'ouverture du fichier en lecture."); //Message d'erreur
    return 1; //Et Fin
  }

  //Calcul de la taille du fichier
  unsigned int taille_fichier = 0;
  char caractere = 0;
  while(caractere != EOF) //Tant que le caractere n'est pas EOF (End Of File -> Fin De Fichier)
  {
    caractere = fgetc(fichier); //Ré-assigner caractere au prochain caractère du fichier
    taille_fichier++; //Et incrémenter taille_fichier
  }

  //Création d'une variable contenant le fichier entier avec taille_fichier comme taille
  char fichier_str[taille_fichier];

  //Remplissage de la variable
  fseek(fichier, 0, SEEK_SET); //De nos jours on peut faire "rewind(fichier);" c'est plus simple

  caractere = 0; //Car caractere vaut EOF, impossible de démarrer la boucle
  unsigned int i = 0; //Un i toujours positif et de bonne humeur

  while(caractere != EOF) //Tant que le caractere n'est pas EOF (End Of File -> Fin De Fichier)
  {
    caractere = fgetc(fichier); //Ré-assigner caractere au prochain caractère du fichier
    fichier_str[i++] = caractere; //Assigner le i ème élément de fichier_str à la valeur de caractere puis incrémenter i
  }

  printf("Fichier Original:\n\n%s\n\n", fichier_str); //Afficher le fichier original actuellement dans fichier_str

  for(i = 0 ; i < taille_fichier ;) //Mettre i à 0, et tant que i est inférieur à taille_fichier...
    cesar(&fichier_str[i++]); //...Appeler la fonction cesar avec l'adresse du i ème élément de fichier_str puis incrémenter i

  printf("Fichier suite au chiffrement:\n\n%s\n\n", fichier_str); //Afficher la version chiffrée du fichier

  fichier = freopen(argv[1], "w", fichier); //On réouvre le fichier en mode écriture //Ré-ouvrir le fichier en mode écriture
  if(fichier == NULL) //En cas d'échec de ré-ouverture
  {
    puts("Erreur pendant l'ouverture du fichier en inscription."); //Message d'erreur
    return 1; //Et fin
  }

  fputs(fichier_str, fichier); //On écrit le nouveau fichier_str dans fichier avec fputs(); !

  puts("Votre fichier est maintenant sous un chiffrement portant le nom d'un certain 'Jules' empereur de Rome."); //On verra après pour les accents sous Windaube

  fclose(fichier); //Fermer le fichier pour des raisons de sécurité

  return 0; //Fin du programme sans erreurs
}
```
  
J'explique plus tard, pour ceux qui ont compris:  
TP: Faire le programme inverse (Déchiffrer le code de césar)  
[Correction du TP](/TP/decesar.c)  
  
PS: On verra comment faire pour les accents sur Windows dans le prochain chapitre ;)  

### fprintf, fwrite, fread, fseek... fichtre !

fprintf et fgetc ont beau nous suffire pour l'instant, il n'existent pas qu'eux dans ce monde !  
Par exemple, beaucoup de gens utilisent fwrite à la place de fputs:  

![](/assets/fwrite.png)  

C'est utile pour afficher seulement les premiers caractères d'un texte sans le couper :D  
Et aussi pour de la précision en général :)  
  
Alors voilà un petit exemple:  
```c
#include <stdio.h>

int main(int argc, char** argv)
{
	//Petite information: atoi(char* str); transforme un string/char* en nombre ('2' -> 2, "42" -> 42...)

	if(argc != 2) //Si il n'y a pas exactement 2 arguments (En comptant le programme)
	{
		puts("Utilisation: alphabetnul <nombre>");
		puts("Action: affiche les <nombre> premières lettres de l'alphabet.");
		return 1;
	}
	
	const unsigned int lettres = atoi(argv[1]); //Nombre non signé -> Si il est négatif il sera très grand :D
	
	if(lettres > 26) //Il y a 26 lettres dans l'alphabet, et comme dit précédemment, si le nombre est négatif il sera très grand...
	{
		puts("Il n'y a que 26 lettres dans l'alphabet latin :P");
		return 1;
	}
	
	//Aussi si on dit 0, pas de lettres >:)
	//On va pas faire bosser fwrite pour si peu ? :snif:
	
	if(!lettres) //0 est faux hein :P
		return 0;
	else if(lettres == 1) //Si on demande une seule lettre...
	{
		putchar('A'); //Emballé c'est pesé !
	}
	
	//Petite information (bis): stdout représente le flux de sortie en ligne de commande du programme
	//En gros, stdout c'est un "faux fichier" qui pointe vers la sortie, et écrire dedans c'est comme utiliser puts(); :D
	
	fwrite("ABCDEFGHIJKLMNOPQRSTUVWXYZ", sizeof(char), lettres, stdout); //Et voilà ! :D
	
	putchar('\n'); //Un petit retour à la ligne ? :P
	
	return 0;
}
```

Aussi (Désolé de ne pas l'avoir dit plus tôt), putchar c'est comme puts, mais ça affiche seulement un caractère :O  
  
On va aussi aller voir du côté de la lecture, car les boucles de fgetc c'est pas joli-joli :c  
Donc souhaitez la bienvenue à fread et fgets !

##### fread

Tout pareil que fwrite, à peu de choses près !  

![](/assets/fread.png)  

Et... un exemple:
```c
#include <stdio.h>

int main(void)
{
	char memoire[101];
	FILE* fichier = NULL;
	
	fopen("test.txt", "r");
	
	if(!fichier)
	{
		puts("Impossible d'ouvrir le fichier test.txt :(");
		return 1;
	}
	
	fread(memoire, sizeof(char), 100, fichier);
	
	puts("Voici les 100 premiers caractères de test.txt:\n");
	puts(memoire);

	return 0;
}
```

##### fgets

![](/assets/fgets.png)  

Ça permet de lire depuis un fichier (Donc flux).  
  
Exemple avec le clavier:  
```c
#include <stdio.h>

int main(void)
{
	char input[32]; //fgets ajoute le null terminator tout seul, pas besoin de demander 33 chars.
	
	fputs("Entrez un truc: ", stdout); //stdout -> écran, fputs ne rajoute pas de retour à la ligne.
	
	fgets(input, 32, stdin); //stdin -> standard input -> entrée standard -> clavier
	
	printf("Vous avez dit: %s\n", input);
	
	return 0;
}
```

###### hmm ?

-"hé mais attends je connais une autre fonction qui s'appelle get-"  
-*giffle*  
  
Chhhutt...  
  
1ère règle: On ne parle pas de gets.  
2nde règle: On NE PARLE PAS de gets.
  
Cette fonction est morte depuis la "révision" C11 du C.  
Sa syntaxe était: `gets(char* pointeur);`  
Vous voyez le problème ? Non ?  
IL EST IMPOSSIBLE DE LIMITER LE NOMBRE DE CARACTÈRES ENTRÉS >:D  
Paye ton buffer overflow :c  

##### fseek

On l'a déjà utilisé avant, c'est simple, il sert à changer l'endroit du "curseur" du fichier.  
Sa syntaxe est:  
`fseek(FILE* flux, long decalage, int d_ou);`  
  
flux c'est le flux/fichier  
decalage c'est le nombre d'octets en mode binaire (Ou une valeur retournée par `ftell();`) à avancer depuis le 0ème caractère  
d_ou c'est soit SEEK_SET (constante qui vaut 0), SEEK_CUR (constante qui vaut 1) ou SEEK_END (constante qui vaut 2)  
  
Dans l'ordre, les valeurs de d_ou permettent de:  
-Partir du début du fichier  
-Partir de la position actuelle du fichier  
-Partir de la fin du fichier  
Et à ça on ajoute le décalage :D  
  
Si il n'y a pas d'erreur, la fonction retourne 0, sinon autre chose.    

##### ftell

À l'inverse de fseek, ftell permet de savoir la position actuelle du fichier.  
Sa syntaxe est:  
`ftell(FILE* flux);`  
  
flux c'est le flux/fichier  
  
Si il n'y a pas d'erreur, la fonction retourne 0, si au contraire il y en a une, la fonction retourne (-1).  
  
Un exemple d'utilisation: Trouver *facilement* la taille d'un fichier  

```c
#include <stdio.h>

int main(void)
{
	FILE* fichier = NULL;
	
	fichier = fopen("test.txt", "r");
	
	if(!fichier)
	{
		fputs("Erreur pendant l'ouverture du fichier test.txt\n", stderr); //stderr -> stdandard error -> erreur standard -> flux pour les erreurs
		//Sur une console/un terminal basique, on voit pas la différence entre stdout et stderr d'ailleurs
		return 1;
	}
	
	fseek(fichier, 0, SEEK_END); //On met le fichier à sa fin donc pas besoin de décalage.
	unsigned int taille fichier = ftell(fichier); //Vu qu'on est à la fin du fichier on peut savoir sa taille facilement
	fseek(fichier, 0, SEEK_SET); //Retour au début, sans même utiliser rewind(fichier); !
	
	char fichier_entier[taille_fichier]; //Créer une variable pour là où garder le fichier
	fread(fichier_entier, sizeof(char), taille_fichier, fichier); //Lire le fichier et le mettre dans la variable ci-dessus
	
	printf("Voilà le contenu entier de test.txt !\n\n%s\n\n-------FIN-------\n", fichier_entier);
	
	return 0;
}
```

# Fin

Je pense que tout ça vous suffira, maintenant vous pouvez faire joujou avec les fichiers !  
Essayez de faire deux-trois trucs intéressant, si vous avez des corrections n'oubliez pas de les mettre en pull request...  
Pour le prochain chapitre je vous ferai juste savoir des trucs intéressants, qui vous seront utiles.  
Exemple: Comment afficher ces fichus accents sur Microdoux Windaube :P  
