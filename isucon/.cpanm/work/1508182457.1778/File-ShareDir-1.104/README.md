# NAME

File::ShareDir - Locate per-dist and per-module shared files

# SYNOPSIS

    use File::ShareDir ':ALL';
    
    # Where are distribution-level shared data files kept
    $dir = dist_dir('File-ShareDir');
    
    # Where are module-level shared data files kept
    $dir = module_dir('File::ShareDir');
    
    # Find a specific file in our dist/module shared dir
    $file = dist_file(  'File-ShareDir',  'file/name.txt');
    $file = module_file('File::ShareDir', 'file/name.txt');
    
    # Like module_file, but search up the inheritance tree
    $file = class_file( 'Foo::Bar', 'file/name.txt' );

# DESCRIPTION

The intent of [File::ShareDir](https://metacpan.org/pod/File::ShareDir) is to provide a companion to
[Class::Inspector](https://metacpan.org/pod/Class::Inspector) and [File::HomeDir](https://metacpan.org/pod/File::HomeDir), modules that take a
process that is well-known by advanced Perl developers but gets a
little tricky, and make it more available to the larger Perl community.

Quite often you want or need your Perl module (CPAN or otherwise)
to have access to a large amount of read-only data that is stored
on the file-system at run-time.

On a linux-like system, this would be in a place such as /usr/share,
however Perl runs on a wide variety of different systems, and so
the use of any one location is unreliable.

Perl provides a little-known method for doing this, but almost
nobody is aware that it exists. As a result, module authors often
go through some very strange ways to make the data available to
their code.

The most common of these is to dump the data out to an enormous
Perl data structure and save it into the module itself. The
result are enormous multi-megabyte .pm files that chew up a
lot of memory needlessly.

Another method is to put the data "file" after the \_\_DATA\_\_ compiler
tag and limit yourself to access as a filehandle.

The problem to solve is really quite simple.

    1. Write the data files to the system at install time.
    
    2. Know where you put them at run-time.

Perl's install system creates an "auto" directory for both
every distribution and for every module file.

These are used by a couple of different auto-loading systems
to store code fragments generated at install time, and various
other modules written by the Perl "ancient masters".

But the same mechanism is available to any dist or module to
store any sort of data.

## Using Data in your Module

`File::ShareDir` forms one half of a two part solution.

Once the files have been installed to the correct directory,
you can use `File::ShareDir` to find your files again after
the installation.

For the installation half of the solution, see [Module::Install](https://metacpan.org/pod/Module::Install)
and its `install_share` directive.

# FUNCTIONS

`File::ShareDir` provides four functions for locating files and
directories.

For greater maintainability, none of these are exported by default
and you are expected to name the ones you want at use-time, or provide
the `':ALL'` tag. All of the following are equivalent.

    # Load but don't import, and then call directly
    use File::ShareDir;
    $dir = File::ShareDir::dist_dir('My-Dist');
    
    # Import a single function
    use File::ShareDir 'dist_dir';
    dist_dir('My-Dist');
    
    # Import all the functions
    use File::ShareDir ':ALL';
    dist_dir('My-Dist');

All of the functions will check for you that the dir/file actually
exists, and that you have read permissions, or they will throw an
exception.

## dist\_dir

    # Get a distribution's shared files directory
    my $dir = dist_dir('My-Distribution');

The `dist_dir` function takes a single parameter of the name of an
installed (CPAN or otherwise) distribution, and locates the shared
data directory created at install time for it.

Returns the directory path as a string, or dies if it cannot be
located or is not readable.

## module\_dir

    # Get a module's shared files directory
    my $dir = module_dir('My::Module');

The `module_dir` function takes a single parameter of the name of an
installed (CPAN or otherwise) module, and locates the shared data
directory created at install time for it.

In order to find the directory, the module **must** be loaded when
calling this function.

Returns the directory path as a string, or dies if it cannot be
located or is not readable.

## dist\_file

    # Find a file in our distribution shared dir
    my $dir = dist_file('My-Distribution', 'file/name.txt');

The `dist_file` function takes two params of the distribution name
and file name, locates the dist dir, and then finds the file within
it, verifying that the file actually exists, and that it is readable.

The filename should be a relative path in the format of your local
filesystem. It will simply added to the directory using [File::Spec](https://metacpan.org/pod/File::Spec)'s
`catfile` method.

Returns the file path as a string, or dies if the file or the dist's
directory cannot be located, or the file is not readable.

## module\_file

    # Find a file in our module shared dir
    my $dir = module_file('My::Module', 'file/name.txt');

The `module_file` function takes two params of the module name
and file name. It locates the module dir, and then finds the file within
it, verifying that the file actually exists, and that it is readable.

In order to find the directory, the module **must** be loaded when
calling this function.

The filename should be a relative path in the format of your local
filesystem. It will simply added to the directory using [File::Spec](https://metacpan.org/pod/File::Spec)'s
`catfile` method.

Returns the file path as a string, or dies if the file or the dist's
directory cannot be located, or the file is not readable.

## class\_file

    # Find a file in our module shared dir, or in our parent class
    my $dir = class_file('My::Module', 'file/name.txt');

The `module_file` function takes two params of the module name
and file name. It locates the module dir, and then finds the file within
it, verifying that the file actually exists, and that it is readable.

In order to find the directory, the module **must** be loaded when
calling this function.

The filename should be a relative path in the format of your local
filesystem. It will simply added to the directory using [File::Spec](https://metacpan.org/pod/File::Spec)'s
`catfile` method.

If the file is NOT found for that module, `class_file` will scan up
the module's @ISA tree, looking for the file in all of the parent
classes.

This allows you to, in effect, "subclass" shared files.

Returns the file path as a string, or dies if the file or the dist's
directory cannot be located, or the file is not readable.

# SUPPORT

Bugs should always be submitted via the CPAN bug tracker

[http://rt.cpan.org/NoAuth/ReportBug.html?Queue=File-ShareDir](http://rt.cpan.org/NoAuth/ReportBug.html?Queue=File-ShareDir)

For other issues, contact the maintainer.

# AUTHOR

Adam Kennedy &lt;adamk@cpan.org>

# SEE ALSO

[File::ShareDir::Install](https://metacpan.org/pod/File::ShareDir::Install), [File::HomeDir](https://metacpan.org/pod/File::HomeDir),
[Module::Install](https://metacpan.org/pod/Module::Install), [Module::Install::Share](https://metacpan.org/pod/Module::Install::Share),
[File::ShareDir::PAR](https://metacpan.org/pod/File::ShareDir::PAR), [Dist::Zilla::Plugin::ShareDir](https://metacpan.org/pod/Dist::Zilla::Plugin::ShareDir)

# COPYRIGHT

Copyright 2005 - 2011 Adam Kennedy.

This program is free software; you can redistribute
it and/or modify it under the same terms as Perl itself.

The full text of the license can be found in the
LICENSE file included with this module.
