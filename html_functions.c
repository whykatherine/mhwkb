/*
 * html_functions.c
 *
 * Copyright 2017 Andy <andy@oceanus>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


void create_html_header (char *html_file, char *title)
{

  FILE *fp = fopen (html_file, "w");
  if (fp == NULL)
  {
    perror ("failure: open file\n");
    exit (1);
  }

  fprintf (fp, "\
<!DOCTYPE html>\n\
<html>\n\
<head>\n\
<meta charset=\"UTF-8\">\n");
  fprintf (fp, "\
<title>%s</title>\n", title);
  fprintf (fp, "<style>\n\
 p.date {\n\
    color: black;\n\
    background-color: #EFDECD;\n\
    font-size: 16px;\n\
    text-align: center;\n\
    display: inline-block;\n\
\n\
}\n\
 a:link, a:visited {\n\
    background-color: #f44336;\n\
    color: white;\n\
    padding: 7px 12px;\n\
    text-align: center;\n\
    text-decoration: none;\n\
    display: inline-block;\n\
}\n\
\n\
a:hover, a:active {\n\
    background-color: red;\n\
}\n\
 a:link.title, a:visited.title {\n\
    background-color: #3B444B;\n\
    color: yellow;\n\
    padding: 7px 12px;\n\
    text-align: center;\n\
    text-decoration: none;\n\
    display: inline-block;\n\
    font-size: 20px;\n\
}\n\
\n\
a:hover.title, a:active.title {\n\
    background-color: black;\n\
    font-size: 20px;\n\
}\n\
p {\n\
  text-align: left;\n\
}\n\
h2 {\n\
  text-align: center;\n\
}\n\
td {\n\
    text-align: left;\n\
}\n\
</style>\n\
</head>\n\
<body>\n\
<h1>%s</h1>\n", title);

  if (fclose (fp) != 0)
  {
    perror ("failure: close file\n");
    exit (1);
  }

}

void create_html_footer (FILE *html_file)
{
  fprintf (html_file, "\n\
  <br /><br />\n\
  <a href=\"index.html\">Back Home</a><br />\n\
  <a href=\"https://github.com/andy5995/mhwkb\">About</a>\n\
  </body>\n\
</html>\n");
}

