//
// Created by Nabil on 17/05/2020.
//

#ifndef UNTITLED_POSITION_H
#define UNTITLED_POSITION_H

#include "../data.hpp"
#include "../name.hpp"
#include <build/ns3/vector.h>


namespace ndn {
    namespace lp {

        class Position {
        public:

            class Error : public ndn::tlv::Error
            {
            public:
                explicit
                Error(const std::string& what)
                        : ndn::tlv::Error(what)
                {
                }
            };
  	    Position();

	    explicit
	    Position(const Block& block);

	    explicit
	    Position(ns3::Vector3D position);

            template<encoding::Tag TAG>
            size_t
            wireEncode(EncodingImpl<TAG>& encoder) const;

            void
            wireDecode(const Block& wire);



            ns3::Vector3D m_position;
        };
    NDN_CXX_DECLARE_WIRE_ENCODE_INSTANTIATIONS(Position);

    }
}

#endif //UNTITLED_POSITION_H

