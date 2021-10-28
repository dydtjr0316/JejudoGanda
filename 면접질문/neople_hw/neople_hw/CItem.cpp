#include "stdafx.h"
#include "CItem.h"

CItem::CItem()
{
	m_usLevelLimit = 0;
	m_usEnhance = 0;
	m_usSmelting = 0;

	m_uiSerialNo;

	m_sName = "";

	m_fWeight = 0.f;

	m_eType = INVEN_TYPE::IDLE;
	m_eExchangeType = EXCHANGE_TYPE::IDLE; // 귀속 교불 등등
}

CItem::CItem()
{
}
