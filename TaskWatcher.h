#ifndef NOTIFIER_H_
#define NOTIFIER_H_

#include "MRApp.h"

class TaskWatcher: public MRApp {
public:
  TaskWatcher();
  virtual ~TaskWatcher();

  virtual void onLaunched(const std::vector<std::string>& parameters);
  virtual std::string onParameterRecieved(const std::string&);
};

#endif /* NOTIFIER_H_ */
