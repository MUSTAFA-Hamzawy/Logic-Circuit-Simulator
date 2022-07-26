#include "Component.h"

bool Component::isLabeld()
{
	if (m_Label == "empty")
	{
		return false;
	}
	return true;
}

void Component::removeLabel()
{
	this->m_Label = "empty";
}

Component::Component(const GraphicsInfo& r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
	selected = false;
	m_Label = "empty";
}

Component::Component()
{

	selected = false;

}

Component::~Component()
{




}

GraphicsInfo Component::getGxfInfo()
{
	return m_GfxInfo;
}

/* Sets the selection of the component */
void Component::setSelected(bool sel) {
	selected = sel;
}


bool Component::isSelected()
{
	return selected;
}

void Component::removeGraphics()
{
	m_GfxInfo.x1 = m_GfxInfo.x2 = m_GfxInfo.y1 = m_GfxInfo.y2 = 0;
}

void Component::setLabel(string l)
{
	m_Label = l;
}

// Returns whether the component is deleted or not 
bool Component::IsDeleted() const {
	return deleted;
}


