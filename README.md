# Mini-projet-Trombi

L'application à réaliser est destinée aux enseignants de Telecom Saint-Etienne. Elle devra aider
l'enseignant à faire le relevé des élèves présents à un cours ou à une séance de travaux dirigés en lui
présentant un trombinoscope sur lequel il pourra cliquer pour sélectionner les étudiants présents. Il
commencera par sélectionner, dans une interface en mode console, un groupe d'étudiants associé à
sa séance de cours (par exemple FISE2-GrA). L'application lui présentera alors, dans une fenêtre
graphique, des vignettes correspondant aux étudiants du groupe. Il pourra alors cliquer sur les
étudiants présents. Lorsqu'il validera son relevé des présents, l'application pourra générer une fiche
d'appel indiquant les élèves présents et les élèves absents.

Pour faciliter la définition des listes d'étudiants et des groupes, l'application se basera sur la lecture
de fichiers textes contenant la liste des étudiants de chaque promotion (FISE1, FISE2, FISE3). Sur
chaque ligne du fichier on trouvera les caractéristiques d'un étudiant : nom, prénom, groupe, nom du
fichier image (ou coordonnées de la vignette dans le fichier trombinoscope).


Les fonctionnalités suivantes devront figurer dans l'application :
1. Lire les fichiers contenant les listes d'étudiants pour constituer automatiquement les
promotions et les groupes disponibles.
2. Afficher les vignettes d'un groupe d'étudiants sélectionné par l'enseignant. Pour pouvoir
accéder à tous les étudiants dans une fenêtre graphique de taille limitée, il faudra prévoir des
boutons de navigation.
3. Permettre de sélectionner ou dé-sélectionner un étudiant à l'aide d'un clic dans sa vignette.
4. Une fois le relevé terminé, l'application devra générer un fichier texte contenant la liste des
étudiants du groupe en indiquant les étudiants présents et absents
