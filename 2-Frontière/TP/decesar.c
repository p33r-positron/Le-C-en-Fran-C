#include <stdio.h>

//Pour votre plus grand bohneur j'ai décidé de faire un code propre pour cette correction de TP

void decesar(char* caractere) //Utilisons les pointeurs !
{
  if((*caractere < 'A' || *caractere > 'Z') && (*caractere < 'a' || *caractere > 'z')) //Si ce n'est pas une lettre latine, fin!
    return; //Une fonction s'arrête après un return
  switch(*caractere) //Parce-que en césar après Z il y a A, ce n'est pas le cas en ASCII.
  {
    case 'A':
      *caractere = 'X';
      break;
    case 'B':
      *caractere = 'Y';
      break;
    case 'C':
      *caractere = 'Z';
    case 'a':
      *caractere = 'x';
      break;
    case 'b':
      *caractere = 'y';
      break;
    case 'c':
      *caractere = 'z';
    default:
      *caractere = (*caractere) - 3; //On enlève 3, on déchiffre en césar !
  }
}

int main(int argc, char** argv)
{
  if(argc != 2) //Vérification de si il y a exactement deux arguments (En comptant le programme, donc un seul vrai argument)
  {
    puts("Utilisation: decesar <fichier>"); //Message d'erreur
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
  //fseek(fichier, 0, SEEK_SET); //De nos jours on peut faire "rewind(fichier);" c'est plus simple
  rewind(fichier); //Donc je l'ai fait ici

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
