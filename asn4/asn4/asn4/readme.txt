MinGW Package Download and Installation Tool
============================================

$Id: readme.txt,v e70f37efc80b 2013/10/04 11:03:38 keithmarshall $

Description
-----------

mingw-get  is a tool to assist users in the management of MinGW and MSYS
software installations.  Configured via an online XML database, which is
managed  by the project maintainers, it offers a choice of graphical and
command line driven user interfaces facilitating selective download  and
installation of packages provided by the project.

The   XML  database  provides  maintainers  with  a  mechanism  for  the
specification of inter-package dependencies; this permits  configuration
of  any  package,  such that the end user may elect to install just that
specific package, leaving mingw-get to ensure that all dependencies will
be automatically satisfied at installation time.


Licensing Terms
---------------

mingw-get  is  free software.  Permission is granted to copy, modify and
redistribute this software, under the  provisions  of  the  GNU  General
Public  License,  Version 3, (or, at your option, any later version), as
published by the Free Software Foundation; see the file  COPYING,  which
is distributed with the mingw-get-lic package, and with the source code,
for licensing details.

Note, in particular, that mingw-get is provided  "as is",  in  the  hope
that  it may prove useful, but WITHOUT WARRANTY OF ANY KIND; not even an
implied WARRANTY OF MERCHANTABILITY, nor of FITNESS FOR  ANY  PARTICULAR
PURPOSE.   Under no circumstances will the author, or the MinGW Project,
accept liability for any damages, however caused, arising from  the  use
of this software.


Release Notes
=============

The  information  presented  below  describes  the  user visible changes
introduced with each release of mingw-get.  The online version  of  this
historical  record is restricted to recent releases; the full history is
recorded in the NEWS file, which is included in the source code package.


mingw-get-0.6.2-mingw32-beta-20131004-1
---------------------------------------

Release date: 2013-10-04

This is a further bug fix release; it addresses the following issues:--

- MinGW-Feature #2036 partially implemented:  profile.xml  now  provides
  for  separate  assignment  of  preferences for each of the CLI and GUI
  clients.  Users are advised to review the changes which have been made
  in  the  distributed  copy  of  defaults.xml,  and to incorporate such
  adjustments  as  they  see  fit,  into  their  own  local  copies   of
  profile.xml;  (alternatively,  those  who don't care to maintain their
  own copy of  profile.xml  should  replace  any  pre-existing  copy  of
  profile.xml with a copy of the distributed defaults.xml).

- MinGW-Bug #2028   partially   resolved:   affiliation   of  individual
  component packages with any package group is now supported;  also  the
  issue  of  only the first affiliation for each package being honoured,
  when displaying the package list, has been corrected.

- MinGW-Bug #2051 fixed: successful  removal  of  meta-packages  is  now
  correctly recorded when updating the GUI's package list display.

- MinGW-Bug #2052  fixed:  the  LUA_PATH  environment  variable  is  now
  correctly specified, for both CLI and GUI clients.

- MinGW-Bug #2054 fixed: pre-remove scripts calling the unlink.js helper
  to  remove  program  shortcuts are now assured that the reference path
  specified with the '--if-linked' attribute will  be  normalized  to  a
  canonical  file  system  form,  before  comparison  with the similarly
  normalized path name stored in any possibly matching shortcut.

- MinGW-Bug #2057  fixed:  mingw-get's  embedded  Lua  interpreter   now
  provides  its own built-in wsh.execute method, which allows invocation
  of the Windows Scripting Host, to run any JScript or VBScript  helper,
  without any need to open a redundant Windows Console.

- The  "Apply Changes" dialogue now assigns default focus to the "Apply"
  button, rather than to the list of packages to be removed; this avoids
  an ugly highlighting issue, when the dialogue is displayed.


mingw-get-0.6.1-mingw32-beta-20130910-1
---------------------------------------

Release date: 2013-09-10

This  is a bug fix release; it corrects a potential buffer overrun issue
within the diagnostic message handler for the GUI client, as  identified
by MinGW-Bug #2026.

In  addition  to  fixing  the  fundamental  buffer  overrun  issue,  the
following changes have been included:--

- Improved diagnosis of possible file  collisions,  resulting  from  the
  installation of packages with conflicting content.

- No  entry  is  now recorded in the installation manifest, for any file
  which is not extracted from its providing package archive,  when  such
  extraction  would  result in file collision; (this fixes the secondary
  issue noted on the ticket for MinGW #2026).

- Carriage returns are now handled appropriately, when  emitted  to  the
  GUI client's diagnostic message handler pseudo-terminal windows.

All  users of mingw-get-0.6.0 are advised to upgrade to this release, as
soon as possible.


mingw-get-0.6.0-mingw32-beta-20130904-1
---------------------------------------

Release date: 2013-09-04

This is the first release to incorporate a  working  prototype  for  the
mingw-get  GUI  client, together with the integrated mingw-get-setup.exe
tool.  With the advent of these additional  capabilities,  the  existing
mingw-get-inst.exe  wrapper becomes redundant, and is now deprecated; it
will be withdrawn after the next mingw-get release.

With this release of mingw-get-setup.exe,  first  time  installation  of
mingw-get  has  become  considerably simpler than previously; please see
the "Installation Instructions" for further information.

In addition to the addition of the GUI client, and the simplified  first
time installation procedure, this release incorporates the following new
user visible features:--

- New "preferences" section in profile.xml; this allows users to  adjust
  the  default behaviour for command line options such as "--start-menu"
  and "--desktop", to allow the automatic creation  of  shortcuts,  (for
  packages which provide them), without requiring explicit specification
  of the option on every mingw-get invocation.  See the comments  within
  defaults.xml, for configuration instructions.

- The  output  from  "mingw-get  --help"  has been revised, to provide a
  better explanation of the use  of  the  "version  selection"  feature,
  which  allows  users to force installation of a particular non-current
  version of any package.

- The "gui.exe" subsidiary program has been renamed as "guistub.exe"; it
  remains  in  place, with this new name, to furnish diagnostics, in the
  event that the user attempts to invoke the GUI from the command  line,
  when  no  GUI  support  has  been  installed.  Such GUI support is now
  provided by  "guimain.exe";  this  may  be  installed  optionally,  by
  choosing to install the "mingw-get-gui" package.

- Internal  "globbing"  of  command  line  arguments  is  now explicitly
  disabled; (any benefit of ever having supported  this  seems  dubious;
  however,  external  "globbing"  by  shells,  such  as MSYS' sh.exe and
  bash.exe is not, and cannot be, affected by this change).

- For users wishing to follow development at the source code level,  the
  master  source  code  repository has been relocated from CVS, to a new
  git  repository  at  git://git.code.sourceforge.net/p/mingw/mingw-get;
  please  refer to the INSTALL file, in the current source distribution,
  for further information on accessing this repository.


mingw-get-0.5-mingw32-beta-20120426-1
-------------------------------------

Release date: 2012-04-26

This is an emergency bug-fix release; it provides an  immediate  interim
work-around  for bug #3520864, circumventing a critical regression which
was introduced in mingw-get-0.5-mingw32-beta-20120416-1, and is  thus  a
mandatory upgrade for users who had previously upgraded to that version.

It also incorporates the correction for bug #3520488.


mingw-get-0.5-mingw32-beta-20120416-1
-------------------------------------

Release date: 2012-04-16

This  milestone  release marks the point at which the code base, for the
CLI implementation, is deemed to have progressed from alpha to beta  (or
better)  quality.  It corrects several packaging deficiencies within the
source code distribution, in addition to fixing two  reported  bugs;  it
also adds several new features.

The following bugs are fixed by this release:--

- #3416013: --reinstall and dependent packages

  Specifically,  in the case of application of the --reinstall option to
  meta-packages, previous releases would have no effect.   This  is  now
  corrected,  such that the --reinstall action is applied recursively to
  each declared requirement of any meta-package, to  the  depth  of  the
  first non-meta package in each requirement chain.

- #3424406: install --reinstall performs an upgrade

  When  performing  the  "install"  action, with the --reinstall option,
  previous releases would consider the availability of upgrades for  the
  package  in question, promoting the "install" action to "upgrade" when
  possible.  This anomaly has now been corrected;  when  specified  with
  the "install" action, the --reinstall option will cause reinstallation
  of the originally installed version, ignoring available upgrades; (the
  former  behaviour  remains  available,  by  specifying the --reinstall
  option together with the "upgrade" action).

The following new features have been implemented:--

- Forced installation of a specified (non-current) release.

  The package name specified  as  the  predicate  of  any  "install"  or
  "upgrade"  action  may  now  be  qualified by a version specification,
  allowing the user to select any known version,  (not  necessarily  the
  most recently released), for installation.  In the case of any package
  which has not been previously installed, the format is any of:

     mingw-get install "package-name=version-spec"
     mingw-get install "package-name<version-spec"
     mingw-get install "package-name<=version-spec"
     mingw-get install "package-name>=version-spec"
     mingw-get install "package-name>version-spec"

  while for any package which has been previously installed, and  is  to
  be  "rolled back" to an earlier release, the same forms are supported,
  using the "upgrade" action in place of "install".

  In each of the above  command  forms,  "package-name"  represents  the
  unqualified  package  name,  as  it  would be specified in any regular
  invocation of mingw-get, and "version-spec" is the  selector  for  the
  desired  version;  (in  the  case of an "=" qualifier, this must be an
  exact match for the desired version, unless it ends with the "*"  wild
  card).   For  example,  if  GCC  has already been installed at version
  4.6.2-1, (the most recent release at this time of writing), it may  be
  rolled back to the last version 4.5 release by:

     mingw-get upgrade "gcc=4.5.*"

  or by using an inequality specifier, to exclude gcc-4.6 and later:

     mingw-get upgrade "gcc<4.6"

  Note  that, particularly in the case of the inequality qualifiers, the
  argument must be quoted, to avoid  interpretation  of  the  inequality
  operator as the shell's redirection operator.

  Also note that any explicit *inclusive* version range, such as:

     mingw-get upgrade "gcc>4.5<4.6"

  is permitted; however no white space is permitted, anywhere within the
  qualified package specification.

- Support for package maintainer scripted installation hooks.

  An embedded script interpreter, based on Lua  version  5.2,  has  been
  incorporated; this provides support for "pre-install", "post-install",
  "pre-remove", and "post-remove" action hooks, which may  be  specified
  by  package  maintainers,  in  the form of Lua scripts embedded within
  "action" elements in any package's XML catalogue entry.

  This capability is further supported by the provision of Lua  modules,
  providing  a  standardised  mechanism for creation of MS-Windows shell
  links, (a.k.a. shortcuts).

- New option: "--desktop"

  Grants permission, to package maintainer specified scripts, to  create
  shortcuts on the user's desktop; alternatively, it may be specified as
  --desktop=all-users, to make such shortcuts available to all users.

- New option: "--start-menu"

  Grants permission, to package maintainer specified scripts, to  create
  shortcuts in the user's start menu; alternatively, it may be specified
  as --start-menu=all-users, to make such  shortcuts  available  in  the
  start menus of all users.


Installation Instructions
=========================

The information which follows describes the procedure for installing and
configuring mingw-get, and for keeping the  installation  current.   The
online  version  of  this document is an abridged form, focussing on the
installation of binary releases; users who prefer to build  and  install
from source are advised to consult the unabridged form of this document,
which may be found  in  the  file  "INSTALL",  within  the  source  code
distribution tarball.

Please report bugs as directed at http://mingw.org/Reporting_Bugs


First Time Installation of a Current Binary Release
---------------------------------------------------

Note that, as of release 0.6.0, the installation procedure for mingw-get
has been significantly simplified.  The installation instructions  which
follow  relate  to this release, and later; for instructions relating to
any earlier release, or if you are unable to run the new setup  tool  on
any  legacy  version  of Windows, please refer to the following section,
under the heading "First Time Installation of a Legacy Binary Release".

To install mingw-get, visit the MinGW files repository at:

    http://sourceforge.net/projects/mingw/files

then, from the "Installer" folder, download and run mingw-get-setup.exe,
and  select  your  choices  from  the  options presented [*], to install
mingw-get.  When this has completed, you will then be offered the option
to  immediately  continue  with the installation of a basic selection of
MinGW packages  [**].   If  you  do  choose  to  continue  with  package
selection, this will be processed by an integrated preview of the mingw-
get GUI  application,  (regardless  of  whether  you  have  accepted  or
declined  the  option  to  install  the  GUI);  to complete your initial
installation:--

- Select individual packages, within the upper  right  hand  "list-view"
  pane of the GUI window;

- From  the  "Package"  menu,  (which also appears as a pop-up, when you
  click the status icon at the left hand side of the list entry), select
  the  option  to  "Mark  for  Installation", in respect of each package
  which you wish to install;

- Having so marked all packages which you  wish  to  install,  from  the
  "Installation"  menu  select  the  "Apply Changes" option, to complete
  your initial installation.

After you have completed the installation  of  mingw-get,  as  described
above,  and  regardless  of  whether  you  chose  to  install additional
packages, or not, you  are  advised  to  review  the  configuration,  as
specified  in  your  profile.xml file, and noting in particular, any new
features which are described in the supplied defaults.xml file,  if  you
have  a profile.xml from a previous release; please refer to the section
below, under the heading "Specifying the Configuration", for details.

[*] By default, mingw-get-setup.exe will offer to install mingw-get into
the  "C:\MinGW" directory.  You are *strongly* recommended to adopt this
default; however, if you do decide to change it, please *do*  choose  an
alternative  with  no  white  space  within  its absolute path name.  In
particular, those who choose to ignore this advice,  and  install  MinGW
into  some  subdirectory  of  (for  example)  C:\Program Files", usually
discover to their cost that certain tools may not work correctly.

[**] The set  of  packages  offered,  as  the  foundation  for  a  basic
installation,  are equivalent to those offered by the mingw-get-inst.exe
companion to earlier releases of mingw-get.  Unlike  mingw-get-inst.exe,
mingw-get-setup.exe,  does  *not*  insist that you install the basic GCC
compiler suite.  You are free to install it, or not, at your own option;
if  you do wish to install it, please select the "mingw32-base" package,
which is the equivalent of the minimum mandatory  selection  imposed  by
mingw-get-inst.exe


First Time Installation of a Legacy Binary Release
--------------------------------------------------

The  instructions  which  follow relate to the installation of mingw-get
releases prior to version 0.6.0; they also apply in the  case  of  later
versions,  where  a  legacy version of Windows may not permit you to run
the new mingw-get-setup.exe tool.  For installation of release 0.6.0, or
any  later  release,  using the new tool, please refer to the preceeding
section, under the heading "First Time Installation of a Current  Binary
Release".

To install mingw-get, visit the MinGW files repository at:

    http://sourceforge.net/projects/mingw/files

and,  from the "Installer/mingw-get-<version>-<class>-<release>" folder,
download your choice of either:

    mingw-get-<version>-mingw32-<class>-<release>-bin.zip

or (preferred, if you know how to unpack it):

    mingw-get-<version>-mingw32-<class>-<release>-bin.tar.xz

Whichever of these you choose to download, you should unpack it into the
directory  in  which  you  intend  to  host your MinGW installation; (we
*strongly* recommend that you adopt our standard of C:\MinGW [*], unless
you  have an exceptional reason to make an alternative choice), then use
your preferred method for assignment of environment variables to add the
appropriate  directory (default C:\MinGW\bin) to your PATH; (this should
be added as a permanent PATH assignment).

Having completed this phase of installation, you may then wish to review
the following section on configuration; if nothing else, you may wish to
copy the supplied defaults.xml file to profile.xml, even if  you  choose
not  to  introduce  any  customisations.   Finally,  to  initialise  the
installation recording database, you should run the command [**]:

    C:\> mingw-get install mingw-get


[*] If you insist on adopting a different directory from the recommended
default,  you  are  *strongly*  advised to avoid any directory which has
white space in its absolute path name; in particular, those  who  choose
to  ignore this advice, and install MinGW into some subdirectory of (for
example) C:\Program Files", usually discover to their cost that  certain
tools may not work correctly.

This document will refer to files as though installed in the recommended
default location, with a path prefix of C:\MinGW.  If, having  read  the
above  warning, you do decide to adopt an alternative installation path,
then please substitute your alternative prefix,  as  appropriate,  where
this document refers to C:\MinGW.

[**] If  you  have  chosen  mingw-get-0.6.2-mingw32-bin.tar.xz  as  your
installation source, rather  than  mingw-get-0.6.2-mingw32-bin.zip,  you
may like to create the directory:

    C:\MinGW\var\cache\mingw-get\packages

(together  with any requisite parents, and adjusting the C:\MinGW prefix
to suit your installation choice, if necessary).  You may then move  the
mingw-get-0.6.2-mingw32-bin.tar.gz  file  to  it,  *before*  you run the
above command; this will relieve mingw-get of the overhead  which  would
be incurred by downloading the file a second time.


Specifying the Configuration
----------------------------

When  you  invoke  mingw-get, it will attempt to read configuration data
from the file:

    C:\MinGW\var\lib\mingw-get\data\profile.xml

(with any necessary adjustment of the C:\MinGW installation  prefix,  as
noted  previously);  if,  and  only if, this file cannot be read, then a
fallback attempt will be made, to read the configuration from:

    C:\MinGW\var\lib\mingw-get\data\defaults.xml

instead.  Of this pair of files, profile.xml is  *not*  included  within
the  mingw-get  distribution,  but defaults.xml *is*.  It is a liberally
commented XML file, which you are advised to copy to create profile.xml;
you  may then modify this, as you see fit, to suit your own installation
requirements. [*]

At the present time, the only entries you should consider  changing  are
the path names specified by the "path" attribute associated with each of
the "sysroot" elements within the  first  (only)  "system-map"  element;
(these  specify  the prefix directory path names for your installation).
You probably want to make the path for  the  "mingw32"  subsystem  match
your choice for your mingw-get installation; (the "%R" notation, used in
defaults.xml, sets it up thus,  regardless  of  whether  you  choose  to
install in C:\MinGW, or an alternative location).

[*] The  recommendation  to copy defaults.xml to profile.xml may seem to
be an unnecessary inconvenience; it is implemented this way in order  to
safeguard any configuration changes you wish to make; during an upgrade,
defaults.xml will be overwritten, but  profile.xml  will  not,  so  your
configuration will be preserved.


Upgrading an Existing Installation to a Newer Binary Release
------------------------------------------------------------

Once  you have completed a first-time installation of mingw-get, whether
from a binary release or by building and installing from source, you may
wish  to upgrade it, as the project team publishes new releases.  Unless
you insist on *always* installing  from  source,  (in  which  case  each
upgrade effectively becomes a fresh first-time installation from the new
source code), and provided:

- you have previously installed mingw-get-0.1-mingw32-alpha-3 or  newer,
  and

- you have completed the first-time installation process, by running

      C:\> mingw-get install mingw-get

then you may upgrade to a newer binary release by running

      C:\> mingw-get update
      C:\> mingw-get upgrade mingw-get

Otherwise,  if  you have a previously unfinalised installation, i.e. you
did not previously run

      C:\> mingw-get install mingw-get

and that previous installation is  of  mingw-get-0.1-mingw32-alpha-3  or
newer, then you may upgrade and finalise by running

      C:\> mingw-get update
      C:\> mingw-get install mingw-get

Alternatively, any previous installation of mingw-get may be upgraded by
simply  performing  a  new  first-time  installation,  overwriting   the
previously installed version; (this is the only option available, if the
original installation predates mingw-get-0.1-mingw32-alpha-3).


$Document: readme.txt $: end of file
