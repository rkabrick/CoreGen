//
// _PoarOpts_h_
//
// Copyright (C) 2017-2020 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

/**
 * \class PoarOpts
 *
 * \ingroup Poar
 *
 * \brief Power/Area speculation options class
 *
 */

#ifndef _POAROPTS_H_
#define _POAROPTS_H_

#include <iostream>
#include <string>

#ifndef POAR_MAJOR_VERSION
#define POAR_MAJOR_VERSION 0
#endif

#ifndef POAR_MINOR_VERSION
#define POAR_MINOR_VERSION 1
#endif

#ifndef POAR_PATCH_VERSION
#define POAR_PATCH_VERSION 0
#endif

class PoarOpts{
private:
  // private variables
  int argc;             ///< PoarOpts: ARGC command line info
  char **argv;          ///< PoarOpts: ARGV command line info
  std::string YamlFile; ///< PoarOpts: Yaml input file
  std::string SCFile;   ///< PoarOpts: StoneCutter input file
  std::string Config;   ///< PoarOpts: configuration file
  std::string OutFile;  ///< PoarOpts: output file

  bool TextOutput;      ///< PoarOpts: defines textual output
  bool YamlOutput;      ///< PoarOpts: defines yaml output
  bool LatexOutput;     ///< PoarOpts: defines latex output
  bool XmlOutput;       ///< PoarOpts: defines xml output

  // private functions

  /// PoarOpts: Print the help menu
  void PrintHelp();

  /// PoarOpts: Print the version info
  void PrintVersion();

public:
  /// PoarOpts: Constructor
  PoarOpts(int,char **);

  /// PoarOpts: Destructor
  ~PoarOpts();

  /// PoarOpts: Parse the command line options
  bool ParseOpts(bool *isHelp);

  /// PoarOpts: Retrieve the configuration file name
  std::string GetConfig() { return Config; }

  /// PoarOpts: Returns whether the text output is selected
  bool IsTextOutput() { return TextOutput; }

  /// PoarOpts: Returns whether the yaml output is selected
  bool IsYamlOutput() { return YamlOutput; }

  /// PoarOpts: Returns whether the latex output is selected
  bool IsLatexOutput() { return LatexOutput; }

  /// PoarOpts: Returns whether the XML output is selected
  bool IsXmlOutput() { return XmlOutput; }

  /// PoarOpts: Retrieves the output file name
  std::string GetOutFile() { return OutFile; }

  /// PoarOpts: Retrieves the design input file
  std::string GetDesignFile() { return YamlFile; }
};

#endif // _POAROPTS_H_
