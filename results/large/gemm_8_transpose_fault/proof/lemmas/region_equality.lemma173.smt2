; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_5 () (_ BitVec 32))
(declare-fun arg0_29 () (_ BitVec 32))
(declare-fun arg1_40 () (_ BitVec 32))
(assert
 (let ((?x67163 (bvmul arg0_29 arg1_5)))
(let ((?x55296 (bvmul (_ bv4294967295 32) ?x67163)))
(let ((?x763 (bvmul arg0_29 arg1_40)))
(let ((?x70865 (bvadd ?x763 ?x55296)))
(and (distinct ?x70865 (_ bv0 32)) true))))))
(check-sat)
