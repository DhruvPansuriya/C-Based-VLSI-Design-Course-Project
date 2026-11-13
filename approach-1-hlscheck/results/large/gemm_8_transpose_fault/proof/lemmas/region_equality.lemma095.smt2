; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_46 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_53 () (_ BitVec 32))
(assert
 (let ((?x75224 (bvmul arg0_14 arg1_46)))
(let ((?x57655 (bvmul (_ bv4294967295 32) ?x75224)))
(let ((?x63771 (bvmul arg0_14 arg1_53)))
(let ((?x60739 (bvadd ?x63771 ?x57655)))
(and (distinct ?x60739 (_ bv0 32)) true))))))
(check-sat)
