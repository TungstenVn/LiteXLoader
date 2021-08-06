#include "ContainerAPI.h"
#include <Kernel/Container.h>
#include "APIHelp.h"
#include "ItemAPI.h"
using namespace std;

//////////////////// Class Definition ////////////////////

ClassDefine<ContainerClass> ContainerClassBuilder =
	defineClass<ContainerClass>("LXL_Container")
		.constructor(nullptr)
		.instanceFunction("getRawPtr", &ContainerClass::getRawPtr)

		.instanceProperty("getSize", &ContainerClass::getSize)

		.instanceFunction("addItem", &ContainerClass::addItem)
		.instanceFunction("addItemToFirstEmptySlot", &ContainerClass::addItemToFirstEmptySlot)
		.instanceFunction("hasRoomFor", &ContainerClass::hasRoomFor)
		.instanceFunction("removeItem", &ContainerClass::removeItem)
		.instanceFunction("getSlot", &ContainerClass::getSlot)
		.instanceFunction("getAllSlots", &ContainerClass::getAllSlots)
		.instanceFunction("removeAllItems", &ContainerClass::removeAllItems)
		.instanceFunction("isEmpty", &ContainerClass::isEmpty)
		.build();

//////////////////// Classes ////////////////////

ContainerClass::ContainerClass(Container* p)
	:ScriptClass(ScriptClass::ConstructFromCpp<ContainerClass>{}), container(p)
{ }

//生成函数
Local<Object> ContainerClass::newContainer(Container* p)
{
	auto newp = new ContainerClass(p);
	return newp->getScriptObject();
}
Container* ContainerClass::extractContainer(Local<Value> v)
{
	if (EngineScope::currentEngine()->isInstanceOf<ContainerClass>(v))
		return EngineScope::currentEngine()->getNativeInstance<ContainerClass>(v)->get();
	else
		return nullptr;
}

//成员函数
Local<Value> ContainerClass::getSize()
{
	try {
		return Number::newNumber(Raw_GetContainerSize(container));
	}
	CATCH("Fail in getSize!")
}

Local<Value> ContainerClass::getRawPtr(const Arguments& args)
{
	try {
		return Number::newNumber((intptr_t)container);
	}
	CATCH("Fail in getRawPtr!")
}

Local<Value> ContainerClass::addItem(const Arguments& args)
{
	CHECK_ARGS_COUNT(args, 1);

	try {
		ItemStack* item = ItemClass::extractItem(args[0]);
		if (!item)
		{
			ERROR("Wrong type of argument in addItem!");
			return Local<Value>();
		}
		return Boolean::newBoolean(Raw_AddItem(container, item));
	}
	CATCH("Fail in addItem!");
}

Local<Value> ContainerClass::addItemToFirstEmptySlot(const Arguments& args)
{
	CHECK_ARGS_COUNT(args, 1);

	try {
		ItemStack* item = ItemClass::extractItem(args[0]);
		if (!item)
		{
			ERROR("Wrong type of argument in addItemToFirstEmptySlot!");
			return Local<Value>();
		}
		return Boolean::newBoolean(Raw_AddItemToFirstEmptySlot(container, item));
	}
	CATCH("Fail in addItemToFirstEmptySlot!");
}

Local<Value> ContainerClass::hasRoomFor(const Arguments& args)
{
	CHECK_ARGS_COUNT(args, 1);

	try {
		ItemStack* item = ItemClass::extractItem(args[0]);
		if (!item)
		{
			ERROR("Wrong type of argument in hasRoomFor!");
			return Local<Value>();
		}
		return Boolean::newBoolean(Raw_HasRoomFor(container, item));
	}
	CATCH("Fail in hasRoomFor!");
}

Local<Value> ContainerClass::removeItem(const Arguments& args)
{
	CHECK_ARGS_COUNT(args, 2);
	CHECK_ARG_TYPE(args[0], ValueKind::kNumber);
	CHECK_ARG_TYPE(args[1], ValueKind::kNumber);

	try {
		return Boolean::newBoolean(Raw_RemoveItem(container, args[0].toInt(), args[1].toInt()));
	}
	CATCH("Fail in removeItem!");
}

Local<Value> ContainerClass::getSlot(const Arguments& args)
{
	CHECK_ARGS_COUNT(args, 1);
	CHECK_ARG_TYPE(args[0], ValueKind::kNumber);

	try {
		ItemStack* item = Raw_GetSlot(container, args[0].toInt());
		if (!item)
		{
			ERROR("Fail to get slot from container!");
			return Local<Value>();
		}
		return ItemClass::newItem(item);
	}
	CATCH("Fail in getSlot!");
}

Local<Value> ContainerClass::getAllSlots(const Arguments& args)
{
	try {
		auto list = Raw_GetAllSlots(container);

		Local<Array> res = Array::newArray();
		for (auto& item : list)
		{
			res.add(ItemClass::newItem(item));
		}
		return res;
	}
	CATCH("Fail in getAllSlots!");
}

Local<Value> ContainerClass::removeAllItems(const Arguments& args)
{
	try {
		return Boolean::newBoolean(Raw_RemoveAllItems(container));
	}
	CATCH("Fail in removeAllItems!");
}

Local<Value> ContainerClass::isEmpty(const Arguments& args)
{
	try {
		return Boolean::newBoolean(Raw_IsEmpty(container));
	}
	CATCH("Fail in isEmpty!");
}