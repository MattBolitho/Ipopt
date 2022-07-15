// Copyright (C) 2022 COIN-OR Foundation
// This code is published under the Eclipse Public License.

#include "IpCuSolverSpInterface.hpp"

namespace Ipopt
{
    bool IpCuSolverSpInterface::InitializeImpl(
        const OptionsList& options,
        const std::string& prefix)
    {
        return true;
    }

    void IpCuSolverSpInterface::RegisterOptions(SmartPtr<RegisteredOptions> roptions)
    {
    }

    ESymSolverStatus IpCuSolverSpInterface::InitializeStructure(
        Index        dim,
        Index        nonzeros,
        const Index* ia,
        const Index* ja)
    {
        // todo
        return ESymSolverStatus::SYMSOLVER_FATAL_ERROR;
    }

    Number* IpCuSolverSpInterface::GetValuesArrayPtr()
    {
        return _values.data();
    }

    ESymSolverStatus IpCuSolverSpInterface::MultiSolve(
        bool         new_matrix,
        const Index* ia,
        const Index* ja,
        Index        nrhs,
        Number*      rhs_vals,
        bool         check_NegEVals,
        Index        numberOfNegEVals)
    {
        // todo
        return ESymSolverStatus::SYMSOLVER_FATAL_ERROR;
    }
    
    Index IpCuSolverSpInterface::NumberOfNegEVals() const
    {
        return _numberOfNegativeEigenValues;
    }

    bool IpCuSolverSpInterface::IncreaseQuality()
    {
        return false;
    }

    bool IpCuSolverSpInterface::ProvidesInertia() const
    {
        return false;
    }

    IpCuSolverSpInterface::EMatrixFormat IpCuSolverSpInterface::MatrixFormat() const
    {
        return CSR_Format_1_Offset;
    }
}
