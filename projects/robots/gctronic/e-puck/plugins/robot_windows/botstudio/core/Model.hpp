// Copyright 1996-2018 Cyberbotics Ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*
 * Description:  Class defining the internal model of BotStudio
 */

#ifndef MODEL_HPP
#define MODEL_HPP

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QStringList>

class Automaton;
class RobotFacade;

class Model : public QObject {
  Q_OBJECT

public:
  static Model *instance();
  static void killInstance();

  Automaton *automaton() const { return mAutomaton; }
  RobotFacade *robotFacade() const { return mRobotFacade; }
  bool isRunning() const { return mIsRunning; }

  void setRunning(bool isRunning);
  void updateValues();

  void fromString(const QString &string);
  QString toString() const;

private:
  Model();
  virtual ~Model();

  int macroVersion() const { return 4; }
  int microVersion() const { return 0; }

  static Model *cInstance;

  Automaton *mAutomaton;
  RobotFacade *mRobotFacade;
  bool mIsRunning;
};

#endif