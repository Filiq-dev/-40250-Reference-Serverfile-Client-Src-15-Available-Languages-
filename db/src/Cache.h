// vim:ts=8 sw=4
#ifndef __INC_DB_CACHE_H__
#define __INC_DB_CACHE_H__

#include "../../common/cache.h"
#include "../../common/auction_table.h"

class CItemCache : public cache<TPlayerItem>
{
    public:
	CItemCache();
	virtual ~CItemCache();

	void Delete();
	virtual void OnFlush();
};

class CPlayerTableCache : public cache<TPlayerTable>
{
    public:
	CPlayerTableCache();
	virtual ~CPlayerTableCache();

	virtual void OnFlush();

	DWORD GetLastUpdateTime() { return m_lastUpdateTime; }
};

// MYSHOP_PRICE_LIST
/**
 * @class	CItemPriceListTableCache
 * @brief	���λ����� ������ �������� ����Ʈ�� ���� ĳ�� class
 * @version	05/06/10 Bang2ni - First release.
 */
class CItemPriceListTableCache : public cache< TItemPriceListTable >
{
    public:

	/// Constructor
	/**
	 * ĳ�� ���� �ð��� �����Ѵ�.
	 */
	CItemPriceListTableCache(void);

	/// ����Ʈ ����
	/**
	 * @param [in]	pUpdateList ������ ����Ʈ
	 *
	 * ĳ�õ� ���������� �����Ѵ�.
	 * �������� ����Ʈ�� ���� á�� ��� ������ ĳ�̵� �������� �ڿ��� ���� �����Ѵ�.
	 */
	void	UpdateList(const TItemPriceListTable* pUpdateList);

	/// ���������� DB �� ����Ѵ�.
	virtual void	OnFlush(void);

    private:

	static const int	s_nMinFlushSec;		///< Minimum cache expire time
};
#endif
