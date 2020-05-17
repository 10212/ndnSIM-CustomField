//
// Created by Nabil on 17/05/2020.
//

#include "Position.hpp"
#include "tlv.hpp"


namespace ndn {
    namespace lp {
	Position::Position() = default;

	Position::Position(const Block& block)
	{
		wireDecode(block);
	}

	Position::Position(ns3::Vector3D position)
	{
		m_position = position;
	}

        template<ndn::encoding::Tag TAG>
        size_t Position::wireEncode(ndn::EncodingImpl<TAG> &encoder) const {
	//Because Vector3D holds three double, so the lenght is set to 3*8 bytes
            size_t length = 24;

            length += encoder.prependVarNumber(length);
            length += encoder.prependVarNumber(tlv::Position);
            return length;
        }

        NDN_CXX_DEFINE_WIRE_ENCODE_INSTANTIATIONS(Position);

        void Position::wireDecode(const Block &wire) {
            if (wire.type() != tlv::Position) {
		std::cout<<"///////////////Wrong TLV type "<<wire.type()<<" != "<<tlv::Position<<std::endl;                
		BOOST_THROW_EXCEPTION(Error("Unexpected TLV-TYPE " + to_string(wire.type())));
  		
            }	    
            const uint8_t* temp = wire.value();
            double x,y,z;
            x = ((double*)temp)[0];
            y = ((double*)temp)[1];
            z = ((double*)temp)[2];

            ns3::Vector3D position = ns3::Vector3D(x,y,z);
            m_position = position;
	}



    }
}
