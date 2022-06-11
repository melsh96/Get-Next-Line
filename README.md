Get Next Line
===
<p>Fonction qui renvoie une ligne
lue depuis un descripteur de fichier en utilisant la méthode des listes chainées.</p>
<br>

### **Function name**
---
get_next_line

### **Prototype**
---
char *get_next_line(int fd);

### **Paramètres**
---
fd : le descripteur de fichier depuis lequel lire

### **Valeur de retour**
---
<p>Le contenu de la ligne lue : comportement correct <br>
NULL : rien d’autre à lire ou une erreur s’est produite</p>


<br>
<br>

```cpp
char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*stash = NULL;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
    // Step 1. Read and create chained list
	read_to_stash(fd, &stash);
	if (stash == NULL)
		return (NULL);
    // Step 2. Extract from each node to buffer till we find a new line
	stash_to_line(stash, &line);
    // Step 3. Clear each node and save last node if new line
	ft_lstclear(&stash, free);
	return (line);
}
```
<br>
<br>

Bonus
===

<p>Faites get_next_line() avec une seule variable statique.</p>

<p>Complétez get_next_line() en lui permettant de gérer plusieurs fd.
Par exemple, si les fd 3, 4 et 5 sont accessibles en lecture, alors il est possible de
les lire chacun leur tour sans jamais perdre les contenus lus sur chacun des fd, et
sans retourner la mauvaise ligne.
<br>

Vous devriez pouvoir appeler get_next_line() une fois avec le fd 3, puis le 4, le
5, puis à nouveau le 3, à nouveau le 4, etc.</p>

<br>
<br>

```cpp
char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*stash[FOPEN_MAX] = {NULL};

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	read_to_stash(fd, &stash[fd]);
	if (stash == NULL)
		return (NULL);
	stash_to_line(stash[fd], &line);
	ft_lstclear(&stash[fd], free);
	return (line);
}
```