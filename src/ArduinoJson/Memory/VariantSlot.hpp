// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include "../Data/JsonVariantData.hpp"

namespace ARDUINOJSON_NAMESPACE {

typedef short VariantSlotDiff;

struct VariantSlot {
  JsonVariantData value;
  VariantSlotDiff next;
  VariantSlotDiff prev;
  const char* key;

  VariantSlot* getNext() {
    return next ? this + next : 0;
  }

  const VariantSlot* getNext() const {
    return next ? this + next : 0;
  }

  VariantSlot* getPrev() {
    return prev ? this + prev : 0;
  }

  void setNext(VariantSlot* slot) {
    next = slot ? VariantSlotDiff(slot - this) : 0;
  }

  void setPrev(VariantSlot* slot) {
    prev = slot ? VariantSlotDiff(slot - this) : 0;
  }
};

}  // namespace ARDUINOJSON_NAMESPACE
