#ifndef SUPERMAP_GEOMETRYCAD_UGGEOCOMPOUNDLINE_HEADER
#define SUPERMAP_GEOMETRYCAD_UGGEOCOMPOUNDLINE_HEADER



#include "Geometry/UGGeometry.h"

namespace UGC {

	//! \brief �����߼��ζ���

class  GEOMETRYCAD_API UGGeoCompoundLine : public UGGeometry
{
public:
	UGGeoCompoundLine(void);
	virtual  ~UGGeoCompoundLine(void);

public:

	//! \brief ��յ�������
	virtual  void Clear();

	//! \brief �õ�ά��, �̶�Ϊ1
	//! \return �õ�ά��,�̶�Ϊ1
	virtual  UGint GetDimension() const;


	//! \brief �õ�����, �̶�Ϊ GeoCompoundParamLine
	virtual  Type GetType() const;


	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \remarks Ϊ���������Ӷ��� ���м��(�м�����ĵ�, �������м����ĵ�)
	virtual  UGPoint2D GetInnerPoint() const;

	//! \brief �����Ӷ���Bounds�Ĵ�С���������и��϶����и����Ӷ��������˳��
	//! \param bMoveUptheMinObj [in] Ϊtrueʱ,С����������;ΪfalseʱС���������档
	 void Adjust(UGbool bMoveUptheMinObj = true);  

	//! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	virtual   UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;	

	//! \brief �õ��ռ�����, ��Ҫ������Ҫ����ά����ͬʱ
	//! ����ͳһ������ʱ��, ����һЩ�ռ��жϺͲ������㷨
	//! \param pPoints �����ĵ���������[out]��
	//! \param pPolyCount ������ÿ���Ӷ�������������[out]��
	//! \param nSubCount �������Ӷ������[out]��
	//! \param nSegmentCount �Բ���������, ÿ�����ηָ��ĸ���[in]��
	//! \remarks ��������������ָ��ļ���,�����߲����ͷ��ڴ�ռ�
	//! \return �ɹ�����true,���򷵻�false��
	virtual   UGbool GetSpatialData( UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;

	//! \brief ת��Ϊ�����
	//! \param geoRegion [out] �õ��������
	//! \param nSegmentCount [in] ����������ÿ�εĲ�ֵ�ĵ�����
	//! \return ���������Ӷ���ɹ�,����true��
	//! \remarks �ڲ�ʵ�־��ǰ�GeoParametricLine�е�ÿһ���Ӷ���ת��ΪRegion,�ټ��뵽geoRegion���ò����С�
	virtual  UGbool ConvertToRegion( UGGeoRegion &geoRegion, UGint nSegmentCount = 0 ) const;		

	//! \brief ת��Ϊ�߶���
	//! \param geoLine [out] �õ����߶���
	//! \param nSegmentCount [in] ����������ÿ�εĲ�ֵ�ĵ�����
	//! \return �߶�������Ӷ���ɹ�,����true��
	//! \remarks �ڲ�ʵ�־��ǰ�GeoParametricLine�е�ÿһ���Ӷ���ת��ΪLine,�ټ��뵽geoLine���ò����С�
	virtual  UGbool ConvertToLine( UGGeoLine &geoLine, UGint nSegmentCount = 0 ) const;	





	//! \brief ����
	//! \param dRatioX X�������ű���
	//! \param dRatioY Y�������ű���
	virtual   void Inflate( UGdouble dRatioX, UGdouble dRatioY);

	//! \brief ����
	//! \param dRatio ���ű���(X,Y������ͬ)
	virtual   void Inflate( UGdouble dRatio);

	//! \brief ƽ��
	//! \param dX ƽ�Ƶ�Xƫ����
	//! \param dY ƽ�Ƶ�Yƫ����
	virtual   void Offset( UGdouble dX, UGdouble dY);

	//! \brief ƽ��
	//! \param ƫ����(X,Y������ͬ)
	virtual   void Offset( UGdouble dOffset);

	//! \brief ƽ��
	//! \param ƽ�Ƶ�ƫ����(�ֱ���UGSize2D�е�x,y����X,Y�����ƫ����)
	virtual   void Offset( const UGSize2D &szOffset);


	//! \brief ��ת
	//! \param pntOrigin ��ת�����ĵ�(ê��,������)
	//! \param dAngle ��ת�Ƕ�
	virtual   void Rotate(const UGPoint2D& pntOrigin, UGdouble dAngle);

	//! \brief ��ת,����һЩ����,�Ա��ڲ����Բ��ý���cos,sin, ������������ʱ�����������Ч��
	//! \remarks dAngle���ƶ���,��GeoText��Ҫ,����Ҫ����
	//! \param pntOrigin ��ת�����ĵ�(ê��,������)
	//! \param dCosAngle ��ת��cosֵ
	//! \param dSinAngle ��ת��sinֵ
	//! \param dAngle ��ת�Ƕ�
	virtual   void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle, double dAngle = 0);


	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds �µ�,�޶���Χ��Bounds
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual   UGbool Resize(const UGRect2D& rcNewBounds); 


	//! \brief ���ζ����Ƿ���Ч
	//! \return ��Ч����true,��Ч����false
	virtual   UGbool IsValid()const;

	//! \brief �õ��Ӷ���ĸ���
	//! \return �����Ӷ���ĸ���
	virtual   UGint GetSubCount() const;

	//! \brief �ֽ⸴�϶���
	//! \param arrGeometry [out] �ֽ��õ����Ӷ��������
	//! \param bToLeaf �Ƿ�ֽ⵽Ҷ����, Ĭ��Ϊfalse
	//! \remarks ���϶�����һ����, ������ֽ⵽Ҷ����, �򴫳���arrGeometry��Ȼ���ܴ��ڸ��϶���(��Ҷ)
	//  ���bToLeaf =true, �򴫳���arrGeometry�п϶�û�� ���϶���
	//! \attention ȡ�����ļ��ζ���ָ������, ��Щָ����Ȼ��ָ��GeoCompound�ڲ����ڴ��ַ, ����ʹ�ú�Ҫdelete;
	//! ��GeoCompound�����仯(������Ӷ���,������յ�)��,��Ҫ��ʹ����Щָ��,��Ϊ�п���ΪҰָ��
	  UGbool Divide(UGArray<UGGeometry *> &arrGeometry, UGbool bToLeaf=false);

	//! \brief ����XML��ʽ����Ϣ
	//! \param versionType GML�İ汾
	//! \param nPace �����Ŀո���Ŀ,ʹ��xml�ַ������������˹��Ķ�; 
	//! ��Ҫ����������ص�xml�ַ�����һ�����ǩ�е�һ����, ͨ��ָ���ո���Ŀ,����ʹ�������
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual   UGString ToXML(GMLVersionType versionType, UGint nPace = 0) const;

	//! \brief ��XML�ַ���������Geometry
	//! \param strXML xml��ʽ�ַ���
	//! \param versionType xml�ַ�����GML�汾
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual   UGbool FromXML(const UGString& strXML, GMLVersionType versionType);


//protected: //! ������Ҫʵ�ֵ�һЩ����������
	virtual   UGRect2D ComputeBounds() const;

	//! \brief �ж��Ӷ����Ƿ�Ϸ�
	//! \param in pSubPart 
	//! \param out
	//! \remarks 
	//! \return �Ϸ�����TRUE,���򷵻�FALSE
	UGbool IsValidSubGeometry( const UGGeometry* pGeometry) const ;

	//! \brief ���ƹ��츴�϶���
	//! \param geoCompound [in] ���еĸ��϶���
	//! \return ���и��϶���Ƿ�,����false��
	  UGbool Make(const UGGeoCompoundLine& geoCompound);

	//! \brief ���������һ���Ӷ���,�˶���ֻ����UGGeoParametricLine����
	//! \return pSub�Ƿ�, ����false��
	  UGbool AddSub( UGGeometry *pGeometry);	

	//! \brief �����Ӷ���
	//! \param nIndex [in] Ҫ�����λ��������
	//! \param pGeoLine [in] �Ӷ���ָ��,�˶���ֻ����UGGeoParametricLine����
	//! \return nSubIndex����pGeoLine�Ƿ�,����false��
	  UGbool InsertSub(UGint nSubIndex, UGGeometry *pGeometry);

	//! \brief ��ָ����λ�����ý�϶���
	//! \param nIndex [in] ָ����λ��������
	//! \param pGeometry [in] ���ζ���ָ��,�˶���ֻ����UGGeoParametricLine����
	//! \return ���ζ���ָ�벻ΪNULL,����true��
	//! \remarks ָ��λ����ԭ�еļ��ζ��󽫱�delete����
	  UGbool SetSub(UGint nIndex, UGGeometry *pGeometry);
		 

	//! \brief ɾ���Ӷ���
	//! \param nIndex [in] Ҫɾ�����Ӷ����λ��������
	//! \return �����Ƿ�, ����false��
	  UGbool DelSub( UGint nIndex );	

	//! \brief �õ�ĳ���Ӷ���
	//! \param nSubIndex [in] �Ӷ���������
	//! \return �����Ӷ���UGGeoParametricLineָ�룬�����Ƿ�, ����false��
	  UGGeometry* GetSub( UGint nSubIndex ) ;
	  UGGeometry* GetSubPtr( UGint nSubIndex ) ;

	//! \brief �õ����󳤶�
	//! \return ���س���
	virtual   UGdouble GetLength() const;	

	//! \brief ��ȡGeometry�Ĵ�С
	//! \param in
	//! \param out
	//! \remarks
	//! \return 
	virtual   UGint GetDataSize() const;

	//! \brief ���浽�洢����
	//! \param stream �洢�õ���, ����֮ǰӦ����Open
	//! \param eCodecType �洢�ı��뷽ʽ
	//! \param bIgnoreStyle �Ƿ���Զ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Save(UGStream& stream, UGDataCodec::CodecType eCodecType=UGDataCodec::encNONE, 
		UGbool bIgnoreStyle = TRUE) const;


	UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bIgnoreStyle,UGbool bSDBPlus /* = FALSE */) const;

	virtual   UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus /* = FALSE */) const;

	virtual   UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType /* = UGDataCodec::encNONE */,UGbool bSDBPlus /* = FALSE */ );


private:

	UGArray<UGGeometry*> m_ChildLine;

	UGuint m_SRID;

};

}
#endif