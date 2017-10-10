/*
 * mhwkb_md2html.c
 * Converts md files for the Mental Health and Wellness Knowledge Base
 * https://github.com/andy5995/mhwkb
 *
 * Usage: mhwkb_md2html <dir_with_md_files>
 *
 * Copyright 2017 Andy Alt <andy400-dev@yahoo.com>
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

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

#define EXIT_OPENDIR_FAILURE 4

#define VERSION ".0.0.01"
#define DATE "2017-10-09"

/* Needs lots of error checking added */

int
main (int argc, char **argv)
{
  char link_href[256];
  char link_title[256];
  char md_line[512];

  int i, href_pos;

  int status;

  struct dirent *entry;
  DIR *files;
  files = opendir (argv[1]);
  if (files == NULL)
  {
    perror ("opendir");
    exit (EXIT_OPENDIR_FAILURE);
  }

  while ((entry = readdir (files)) != NULL)
  {
    if (strcmp (entry->d_name, ".") == 0 || strcmp (entry->d_name, "..") == 0)
      continue;

    FILE *md_file = fopen (entry->d_name, "r");

    while (fgets (md_line, 512, md_file) != NULL)
    {
      link_href[0] = '\0';
      link_title[0] = '\0';

      if (md_line[0] == '[')
      {

        for (i = 0; md_line[i] != ']'; i++)
        {
          if (md_line[i] != '[')
          {
            link_title[i - 1] = md_line[i];
          }
        }

        link_title[i - 1] = '\0';

        i++;

        href_pos = 0;

        for (; md_line[i] != ')'; i++)
        {
          if (md_line[i] != '(')
            link_href[href_pos++] = md_line[i];
        }
        link_href[href_pos++] = '\0';
        printf ("<a href=\"%s\">%s</a><br />\n", link_href, link_title);

        fgets (md_line, 512, md_file);
        printf ("date: %s\n", md_line);
        fgets (md_line, 512, md_file);
        printf ("%s\n", md_line);
        printf ("<br /><br />");
      }
    }

    fclose (md_file);
  }

  status = closedir (files);
  if (status)
    perror ("closedir");

  return 0;
}
