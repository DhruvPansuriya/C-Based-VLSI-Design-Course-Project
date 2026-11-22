; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x492210 (bvmul arg0_13 arg1_6)))
(let ((?x488852 (bvmul (_ bv4294967295 32) ?x492210)))
(let ((?x20299 (bvmul arg0_13 arg1_7)))
(let ((?x482853 (bvadd ?x20299 ?x488852)))
(and (distinct ?x482853 (_ bv0 32)) true))))))
(check-sat)
