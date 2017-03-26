#pragma once


/** CHarvestDlg dialog*/

class CHarvestDlg : public CDialog
{
	DECLARE_DYNAMIC(CHarvestDlg)

public:
	/**constructor
	* \param pParent*/
	CHarvestDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CHarvestDlg();

	/**get harvest frame
	* \returns harvest frame*/
	int GetHarvestFrame(){ return mHarvestFrame; }

	/**set harvest frame
	* \param frame we're setting*/
	void SetHarvestFrame(int frame){ mHarvestFrame = frame; }

// Dialog Data
	enum { IDD = IDD_HARVESTDLG };

protected:
	/**data exchange
	* \param pDX*/
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	int mHarvestFrame = 230;		///< harvest frame
};
