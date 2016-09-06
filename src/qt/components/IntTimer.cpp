//
// Created by Colliot on 2016/9/6.
//

#include "IntTimer.h"

W_OBJECT_IMPL(IntTimer)
void IntTimer::fireTimer() {
  emit timeoutWithId(id);
}

IntTimer::IntTimer(QObject *parent, int id) : QTimer(parent), id(id) {
  connect(this, SIGNAL(timeout()), this, SLOT(fireTimer()));
}
